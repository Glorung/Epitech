#include	<stdlib.h>
#include	<stdio.h>
#include	<cstring>

#include	"autocompletion.hpp"

void		print_usage()
{
  std::cerr << USAGE1 << USAGE2 << USAGE3 << std::endl;
}

int		main(int ac, char **av)
{
  Exec		exec;

  if (ac == 2)
    {
      std::string file = std::string(av[1]);
      if (file == "-h" || file == "--help")
	print_usage();
      else
	{
	  if ((exec.get_file(file)) == -1)
	    return (ERROR_V);
	  if ((exec.parser()) == -1)
	    return (ERROR_V);
	  if (exec.start() == -1)
	    return (ERROR_V);
	}
      return (0);
    }
  print_usage();
  return (ERROR_V);
}
