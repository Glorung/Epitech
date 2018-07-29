//
// string_utils.cpp for string in /home/glorung/Piscine/autoCompletion/src
// 
// Made by 
// Login   <glorung@epitech.net>
// 
// Started on  Mon Jul  4 14:09:14 2016 
// Last update Wed Jul  6 09:08:17 2016 
//

#include	<cstring>
#include	"autocompletion.hpp"

int		check_char(std::string &str, char c)
{
  unsigned int	i;
  int		cnt;

  i = 0;
  cnt = 0;
  while (i < str.length())
    {
      if (str[i] == c)
	++cnt;
      ++i;
    }
  return (cnt);
}

int		checkVector_char(std::vector<char> getVector, char c)
{
  unsigned int	i;

  if (getVector.size() == 0)
    return (0);
  i = 0;
  while (i < getVector.size())
    {
      if (getVector[i] == c)
	return (1);
      i = i + 1;
    }
  return (0);
}

int		vectorCmp(std::vector<std::string> v1, std::vector<std::string> v2)
{
  std::string	str1;
  std::string	str2;
  unsigned int	i;

  i = 0;
  while (i < v1.size())
      str1 += v1[i++];
  i = 0;
  while (i < v2.size())
    str2 += v2[i++];
  return (strcmp(str1.c_str(), str2.c_str()));
}

void		replace_char(std::string &str, char from, char to)
{
  unsigned int	i;

  i = 0;
  while (i < str.length())
    {
      if (str[i] == from)
	str[i] = to;
      i = i + 1;
    }
}

void		epur_str(std::string &str)
{
  unsigned int	i;
  unsigned int	j;

  replace_char(str, '\t', ' ');
  i = 0;
  while (i < str.length() && str[i] == ' ')
    ++i;
  j = 0;
  while (i < str.length())
    {
      while (i < str.length() && str[i] != ' ')
	str[j++] = str[i++];
      if (str[i] == ' ')
	str[j++] = str[i++];
      while (i < str.length() && str[i] == ' ')
	i++;
    }
  if (j == 0)
    str.erase(0, str.length());
  else if (str[j - 1] == ' ')
    str.erase(j - 1, str.length());
  else
    str.erase(j, str.length());
}

// StrToVector

std::vector<std::string>	strToVector(std::string str, const std::string &separator)
{
  std::vector<std::string>	tab;
  std::string			next;
  char				*get;

  get = strtok((char *)(str.c_str()), (char *)(separator.c_str()));
  if (get == NULL)
    {
      std::cerr << "strToVector NULL" << std::endl;
    return (tab);
    }
  next = get;
  tab.push_back(next);
  while ((get = strtok(NULL, (char *)(separator.c_str()))) != NULL)
    {
      next = get;
      tab.push_back(next);
    }
  return (tab);
}

void			toLower(std::string &str)
{
  unsigned int		i;

  i = 0;
  while (i < str.length())
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	  str[i] = str[i] + 32;
      i = i + 1;
    }
}

std::string		toUpper(std::string str)
{
  unsigned int		i;

  i = 0;
  while (i < str.length())
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	  str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
