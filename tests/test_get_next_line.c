
//############################################################################//
//===========================  SAMPLE TEST FILE  =============================//
// For more info, check out readme                                            //
// Also, check for testing fundamentals                                       //
// Hail to the QAs!                                                           //
//############################################################################//

// fill with your header files
#include "./Unity-2.6.1/src/unity.h"
#include "./utils/utils.h"
#include "../get_next_line.h"
#include <fcntl.h>

#include <stdio.h>

// A sample file to be this test target
// #include "../sample.h"

void	setUp()
{
	return ;
}

void	tearDown()
{
	remove("output.txt");
	remove("control.txt");
	return ;
}

void	two_strings_should_be_equal(void)
{
	TEST_ASSERT_EQUAL_STRING("TEST", "TEST");
}

void	test_printf(void)
{
	char	*output;
	char	*def = "teste %s";
	char	*s = "Ops!";
	int		count = 0;
	
	CAPTURE_PRINT("output.txt", count, printf, def, s);
	output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("Ops!", output, "Error!");
	free(output);
	remove("output.txt");
}
void	should_return_file_content(void)
{
	int		fd_control;
	int		count_control;
	int		count_output;
	char	*ptr_control;
	char	*ptr_output;
	char	*content = "Teste de conteudo";

	CAPTURE_PRINT("control.txt", count_control, printf, "%s", content);

	fd_control = open("control.txt", O_RDONLY);
	freopen("output.txt", "w+", stdout);
	count_output = printf("%s", get_next_line(fd_control));
	freopen("/dev/tty", "w", stdout);

	ptr_control = read_file_to_str("control.txt");
	ptr_output = read_file_to_str("output.txt");
	TEST_ASSERT_EQUAL_STRING_MESSAGE(ptr_control, ptr_output, "ERRO");
	free(ptr_control);
	free(ptr_output);
	close(fd_control);
}

int	main(void)
{
UNITY_BEGIN();
RUN_TEST(should_return_file_content);
return UNITY_END();
}
