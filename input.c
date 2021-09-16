#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "cmdline.h"

void read_line(char* prompt, char** output) {
	*output = readline(prompt);

	if (output && *output)
		add_history(*output);
}

int main(int argc, char** argv) {
	struct gengetopt_args_info args;
	cmdline_parser(argc, argv, &args);

	char* output;
	// Copy stdout descriptor
	int stdout_descriptor = dup(fileno(stdout));

	// Open stdout to tty
	freopen("/dev/tty", "w", stdout);
	if (args.history_file_given)
		read_history(args.history_file_arg);

	read_line(args.prompt_arg, &output);

	if (args.history_file_given)
		write_history(args.history_file_arg);

	// Reopen original stdout
	dup2(stdout_descriptor, fileno(stdout));
	close(stdout_descriptor);
	clearerr(stdout);

	printf("%s\n", output);
}
