/* **************************************************************************
 */
/*                                                                            */
/*                                                        :::      :::::::: */
/*   main.c                                             :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+ */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+ */
/*   Created: 2025/06/08 13:27:44 by lepereir          #+#    #+# */
/*   Updated: 2025/06/08 14:35:29 by lepereir         ###   ########.fr */
/*                                                                            */
/* **************************************************************************
 */

#include "minishell.h"
#include "unity/unity.h"

static t_minishell test_shell;

static char *test_env[] = { "PATH=/usr/local/bin:/usr/bin:/bin",
                            "HOME=/home/user",
                            "USER=student",
                            "LANG=en_US.UTF-8",
                            "SHELL=/bin/bash",
                            "PWD=/current/directory",
                            "EMPTY_VAR=",
                            "SPECIAL_CHARS=value with spaces!@#$%",
                            "LONG_VALUE=this_is_a_very_long_environment_"
                            "variable_value_that_tests_our_function",
                            NULL };

void
setUp (void)
{
  size_t count;
  size_t i;

  count = 0;
  i = 0;
  while (test_env[count])
    count++;
  test_shell.envp = envp_dup (test_env);
  TEST_ASSERT_NOT_NULL (test_shell.envp);
}

void
tearDown (void)
{
}

void
test_envp_dup (void)
{
  char *envp[] = { "USER=root", "PATH=/bin:/usr/bin", NULL };
  char **copy = envp_dup (envp);
  TEST_ASSERT_NOT_NULL (copy);
  TEST_ASSERT_EQUAL_STRING ("USER=root", copy[0]);
  TEST_ASSERT_EQUAL_STRING ("PATH=/bin:/usr/bin", copy[1]);
  TEST_ASSERT_NULL (copy[2]);

  free (copy[0]);
  free (copy[1]);
  free (copy);
}

void
test_envp_get_existing_variables (void)
{
  char *result;

  // Test PATH
  result = envp_get (&test_shell, "PATH");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("/usr/local/bin:/usr/bin:/bin", result);

  // Test HOME
  result = envp_get (&test_shell, "HOME");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("/home/user", result);

  // Test USER
  result = envp_get (&test_shell, "USER");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("student", result);

  // Test LANG
  result = envp_get (&test_shell, "LANG");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("en_US.UTF-8", result);

  // Test SHELL
  result = envp_get (&test_shell, "SHELL");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("/bin/bash", result);

  // Test PWD
  result = envp_get (&test_shell, "PWD");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("/current/directory", result);
}

void
test_envp_get_empty_variable (void)
{
  char *result = envp_get (&test_shell, "EMPTY_VAR");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("", result);
}

void
test_envp_get_special_characters (void)
{
  char *result = envp_get (&test_shell, "SPECIAL_CHARS");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING ("value with spaces!@#$%", result);
}

void
test_envp_get_long_value (void)
{
  char *result = envp_get (&test_shell, "LONG_VALUE");
  TEST_ASSERT_NOT_NULL (result);
  TEST_ASSERT_EQUAL_STRING (
      "this_is_a_very_long_environment_variable_value_that_tests_our_function",
      result);
}

void
test_envp_get_nonexistent_variables (void)
{
  // Test completely non-existent variables
  TEST_ASSERT_NULL (envp_get (&test_shell, "NONEXISTENT"));
  TEST_ASSERT_NULL (envp_get (&test_shell, "FAKE_VAR"));
  TEST_ASSERT_NULL (envp_get (&test_shell, "DOES_NOT_EXIST"));
  TEST_ASSERT_NULL (envp_get (&test_shell, "MISSING"));
}

void
test_envp_get_partial_matches (void)
{
  // These should NOT match existing variables
  TEST_ASSERT_NULL (envp_get (&test_shell, "PA"));         // Partial of PATH
  TEST_ASSERT_NULL (envp_get (&test_shell, "HOM"));        // Partial of HOME
  TEST_ASSERT_NULL (envp_get (&test_shell, "US"));         // Partial of USER
  TEST_ASSERT_NULL (envp_get (&test_shell, "PATH_EXTRA")); // Extra chars
  TEST_ASSERT_NULL (envp_get (&test_shell, "HOMEDIR"));    // Extra chars
}

void
test_envp_get_edge_cases (void)
{
  // Test empty key
  TEST_ASSERT_NULL (envp_get (&test_shell, ""));

  // Test single character keys (if they don't exist)
  TEST_ASSERT_NULL (envp_get (&test_shell, "A"));
  TEST_ASSERT_NULL (envp_get (&test_shell, "Z"));
}

void
test_envp_get_null_inputs (void)
{
  // Test NULL shell pointer
  TEST_ASSERT_NULL (envp_get (NULL, "PATH"));

  // Test NULL key
  TEST_ASSERT_NULL (envp_get (&test_shell, NULL));

  // Test both NULL
  TEST_ASSERT_NULL (envp_get (NULL, NULL));
}

void
test_envp_get_null_envp (void)
{
  t_minishell empty_shell;
  empty_shell.envp = NULL;

  // Should return NULL when envp is NULL
  TEST_ASSERT_NULL (envp_get (&empty_shell, "PATH"));
}

void
test_envp_get_empty_envp (void)
{
  t_minishell empty_shell;
  char *empty_env[] = { NULL };
  empty_shell.envp = empty_env;

  // Should return NULL when envp is empty
  TEST_ASSERT_NULL (envp_get (&empty_shell, "PATH"));
}

void
test_envp_get_case_sensitivity (void)
{
  // Environment variables are case-sensitive
  TEST_ASSERT_NULL (envp_get (&test_shell, "path")); // lowercase
  TEST_ASSERT_NULL (envp_get (&test_shell, "Path")); // mixed case
  TEST_ASSERT_NULL (envp_get (&test_shell, "home")); // lowercase
  TEST_ASSERT_NULL (envp_get (&test_shell, "user")); // lowercase

  // But correct case should work
  TEST_ASSERT_NOT_NULL (envp_get (&test_shell, "PATH"));
  TEST_ASSERT_NOT_NULL (envp_get (&test_shell, "HOME"));
  TEST_ASSERT_NOT_NULL (envp_get (&test_shell, "USER"));
}

void
test_envp_get_return_pointer_validity (void)
{
  char *result = envp_get (&test_shell, "PATH");
  TEST_ASSERT_NOT_NULL (result);

  // The returned pointer should point to the correct location
  // It should be the same as manually calculating the position
  char *expected = test_shell.envp[0] + 5; // "PATH=" is 5 chars
  TEST_ASSERT_EQUAL_PTR (expected, result);

  // Test another variable
  result = envp_get (&test_shell, "HOME");
  TEST_ASSERT_NOT_NULL (result);
  expected = test_shell.envp[1] + 5; // "HOME=" is 5 chars
  TEST_ASSERT_EQUAL_PTR (expected, result);
}

void
test_envp_del (void)
{
  TEST_ASSERT_NOT_NULL (envp_get (&test_shell, "PATH"));
  TEST_ASSERT_EQUAL_INT (envp_del (&test_shell, "PATH"), 0);
  TEST_ASSERT_EQUAL_INT (envp_del (&test_shell, "DOES_NOT_EXIST"), 1);
  TEST_ASSERT_NULL (envp_get (&test_shell, "PATH"));
}

void
test_envp_set_update (void)
{
  TEST_ASSERT_NOT_NULL (envp_get (&test_shell, "PATH"));
  TEST_ASSERT_EQUAL_INT (envp_set (&test_shell, "PATH", "ANYTHING"), 0);
  TEST_ASSERT_EQUAL_STRING (envp_get (&test_shell, "PATH"), "ANYTHING");
}

void
test_envp_set_new (void)
{
  TEST_ASSERT_NULL (envp_get (&test_shell, "NEW_ENV_VAR"));
  TEST_ASSERT_EQUAL_INT (envp_set (&test_shell, "NEW_ENV_VAR", "NEW_VALUE"),
                         0);
  TEST_ASSERT_NOT_NULL (envp_get (&test_shell, "NEW_ENV_VAR"));

  TEST_ASSERT_EQUAL_STRING (envp_get (&test_shell, "NEW_ENV_VAR"),
                            "NEW_VALUE");
}

int
main (void)
{
  UNITY_BEGIN ();

  RUN_TEST (test_envp_dup);

  RUN_TEST (test_envp_get_existing_variables);
  RUN_TEST (test_envp_get_empty_variable);
  RUN_TEST (test_envp_get_special_characters);
  RUN_TEST (test_envp_get_long_value);

  RUN_TEST (test_envp_get_nonexistent_variables);
  RUN_TEST (test_envp_get_partial_matches);
  RUN_TEST (test_envp_get_edge_cases);

  RUN_TEST (test_envp_get_null_inputs);
  RUN_TEST (test_envp_get_null_envp);
  RUN_TEST (test_envp_get_empty_envp);

  RUN_TEST (test_envp_get_case_sensitivity);
  RUN_TEST (test_envp_get_return_pointer_validity);

  RUN_TEST (test_envp_del);

  RUN_TEST (test_envp_set_update);
  RUN_TEST (test_envp_set_new);

  return UNITY_END ();
}
