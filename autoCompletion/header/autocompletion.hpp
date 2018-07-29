#pragma			once

#include		<iostream>
#include		<string>
#include		<vector>
#include		<stdlib.h>


# define USAGE1 "USAGE\n\t./autocompletion dictionnary\n\n"
# define USAGE2 "DESCRIPTION\n\tdictionnary\tfile,"
# define USAGE3 "containing one adress per line, serving as kmowledge base"
# define ERROR_V (84)

// autoCompletion.cpp

struct			City
{
  std::string		name;
  unsigned int		size;
};

struct			Town
{
  std::string			line;
  std::vector<std::string>	city;
  int				nb;
  std::string			streetType;
  std::vector<std::string>	streetName;
};

class				AutoCompletionStreet
{
  unsigned int			pos;
  std::string			get;
  std::vector<City>		getTown;

public:
  // fct
  void				Init(std::vector<Town>);
  int				IsInStreetName(std::string);
  void				displayChoice(std::vector<char>);
  void				displayFinalChoice(std::vector<std::vector<std::string> > &);
  bool				myStreetNameCmp(Town, Town);
  std::vector<char>		getChoice();
  bool				streetNameExist(std::vector<Town>, std::vector<std::string>);
  std::vector<Town>		removeUselessTown(std::vector<Town>);
  std::vector<std::vector<std::string> >		getFinalChoice(std::vector<Town>);
  int				checkEndWord();
  void				updateVector();
  char				getInput(int, int);
  std::vector<std::string>	autoGetTown(std::vector<Town>);
};

class				AutoCompletionTown
{
  unsigned int			pos;
  std::string			get;
  std::vector<City>		getTown;

public:
  // fct
  void				Init(std::vector<Town>);
  int				IsInCity(std::string);
  void				displayChoice(std::vector<char>);
  void				displayFinalChoice(std::vector<std::vector<std::string> > &);
  bool				myCityCmp(Town, Town);
  std::vector<char>		getChoice();
  bool				cityExist(std::vector<Town>, std::vector<std::string>);
  std::vector<Town>		removeUselessTown(std::vector<Town>);
  std::vector<std::vector<std::string> >		getFinalChoice(std::vector<Town>);
  int				checkEndWord();
  void				updateVector();
  char				getInput(int, int);
  std::vector<std::string>	autoGetTown(std::vector<Town>);
};

// exec.cpp

class			Exec
{
 public:
  Exec();
  ~Exec();

  int				get_file(std::string);
  int				parser();
  std::vector<std::string>	getTownName(std::string);
  int				getTownNbr(std::string);
  std::string			getStreetType(std::string);
  std::vector<std::string>	getStreetName(std::string);
  void				parserLine(std::string &, std::string &);
  void				treeGeneration();
  void				updateExecTown(std::vector<std::string>);
  int				start();
  int				compareElem(Town, Town);
  void				checkDoublon();
 private:
  std::vector<std::string>	file;
  std::vector<Town>		town;
  std::vector<Town>		backup;
  std::string			input;
  AutoCompletionStreet		completionStreet;
  AutoCompletionTown		completionTown;
};

// main.cpp
int				main(int, char **);
void				print_usage();
// string_utils.cpp
void				epur_str(std::string &);
int				vectorCmp(std::vector<std::string>, std::vector<std::string>);
std::vector<std::string>	strToVector(std::string, const std::string &);
void				toLower(std::string &);
std::string			toUpper(std::string);
int				checkVector_char(std::vector<char>, char);
// getEntry.cpp
std::string			getEntry();
