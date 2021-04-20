#include "header.h"

static void			take_terminal_type(char **terminal)
{
	*terminal = getenv("TERM");
	if (NULL == *terminal)
	{
		*terminal = getenv("TERM");
		if (NULL == *terminal)
			*terminal = ft_strdup("xterm-256color");
	}
}

void 		history_init(t_hist *hist, struct termios *term, t_pars *pa)
{
	tcgetattr(0, term);
	take_terminal_type(&hist->terminal);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	tcsetattr(0, TCSANOW, term);
	hist->term = term;
	if (-1 == tgetent(0, hist->terminal))
	{
		ft_errors(TERM_ERRORS);
		exit(TERM_ERRORS);
	}
}

void 		term_off(t_hist *hist)
{
	hist->term->c_lflag |= (ECHO);
	hist->term->c_lflag |= (ICANON);
	tcsetattr(0, TCSANOW, hist->term);
	if (-1 == tgetent(0, hist->terminal))
	{
		ft_errors(TERM_ERRORS);
		exit(TERM_ERRORS);
	}

}