//
// exec.cpp for autocompletion in /home/glorung/Piscine/autoCompletion/src
// 
// Made by 
// Login   <glorung@epitech.net>
// 
// Started on  Mon Jul  4 11:00:26 2016 
// Last update Wed Jul  6 15:37:12 2016 
//

#include		<fstream>
#include		<sstream>
#include		<stdlib.h>
#include		<string.h>

#include		"autocompletion.hpp"

Exec::Exec()
{}

Exec::~Exec()
{}

// Fct

int			Exec::get_file(std::string filename)
{
  std::ifstream		fd(filename.c_str(), std::ios::in);
  std::string		line;

  if (!fd)
    return (-1);
  while (getline(fd, line))
    this->file.push_back(line);
  fd.close();
  return (0);
}

// Parser

int			Exec::parser()
{
  unsigned int		i;
  std::string		backup;

  i = 0;
  while (i < file.size())
    {
      backup = file[i];
      epur_str(file[i]);
      parserLine(backup, this->file[i]);
      i = i + 1;
    }
  i = 0;
  while (i < town.size())
    {
      unsigned int	j;
      std::string	data;

      j = 0;
      while (j < town[i].city.size())
	{
	  toLower(town[i].city[j]);
	  ++j;
	}
      j = 0;
      while (j < town[i].streetName.size())
	{
	  toLower(town[i].streetName[j]);
	  ++j;
	}
      i = i + 1;
    }
  // checkDoublon();
  // if (town.size() == 0)
  //   exit(0);
  // else if (town.size() == 1)
  //   std::cout << town[0].line << std::endl;
  return (0);
}

int			Exec::compareElem(Town t1, Town t2)
{
  if (strcasecmp(t1.line.c_str(), t2.line.c_str()) == 0)
    return (0);
  return (1);
}

void			Exec::checkDoublon()
{
  unsigned int		i;
  unsigned int		j;

  i = 0;
  while (i < town.size())
    {
      j = 0;
      while (j < town.size())
	{
	  if (i != j && compareElem(town[i], town[j]) == 0)
	    {
	      town.erase(town.begin() + j);
	      i = i - 1;
	      break;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

std::vector<std::string>	Exec::getTownName(std::string str)
{
  std::vector<std::string>	tab;

  tab = strToVector(str, ",");
  if (tab.size() != 2)
    return (std::vector<std::string>());
  else
    return (strToVector(tab[0], " "));
  return (tab);
}

int			Exec::getTownNbr(std::string str)
{
  std::vector<std::string>	tab;
  std::vector<std::string>	tab2;

  tab = strToVector(str, ",");
  if (tab.size() != 2)
      return (0);
  else
    {
      tab2 = strToVector(tab[1], " ");
      if (tab2.empty())
	return (0);
      return (atoi(tab2[0].c_str()));
    }
  return (0);
}

std::string			Exec::getStreetType(std::string str)
{
  std::vector<std::string>	tab;
  std::vector<std::string>	tab2;
  std::string			streetType[10] =
    {"allée", "avenue",
     "boulevard", "chemin",
     "impasse", "place",
     "quai", "rue",
     "square", ""};
  unsigned int			i;

  tab = strToVector(str, ",");
  if (tab.size() != 2)
    return (std::string());
  else
    {
      tab2 = strToVector(tab[1], " ");
      if (tab2.size() < 2)
	return (std::string());
      i = 0;
      while (!streetType[i].empty() &&
	     tab2[1].compare(streetType[i]) != 0)
	  ++i;
      if (!streetType[i].empty() &&
	  tab2[1].compare(streetType[i]) == 0)
	return (streetType[i]);
      else
	return (std::string());
    }
  return (std::string());
}

std::vector<std::string>	Exec::getStreetName(std::string str)
{
  std::vector<std::string>	tab;
  std::vector<std::string>	tab2;
  std::vector<std::string>	tab3;
  unsigned int			i;

  tab = strToVector(str, ",");
  if (tab.size() != 2)
    return (std::vector<std::string>());
  else
    {
      tab2 = strToVector(tab[1], " ");
      if (tab2.size() < 2)
	return (std::vector<std::string>());
      i = 1;
      while (i < tab2.size())
	{
	  tab3.push_back(tab2[i]);
	  ++i;
	}
      return (tab3);
    }
  return (std::vector<std::string>());
}

void			Exec::parserLine(std::string &backup,
					 std::string &line)
{
  std::vector<std::string>	tab;
  Town				new_town;

  new_town.line = line;
  new_town.city = getTownName(line);
  new_town.nb = getTownNbr(line);
  new_town.streetType = getStreetType(line);
  new_town.streetName = getStreetName(line);
  // if (new_town.city.empty())
  //   {
  //     std::cout << "city empty" << std::endl;
  //   }
  // if (new_town.nb <= 0)
  //   {
  //     std::cout << "streetnb empty" << std::endl;
  //   }
  // if (new_town.streetType.empty())
  //   {
  //     std::cout << "streettype empty" << std::endl;
  //   }
  // if (new_town.streetName.empty())
  //   {
  //     std::cout << "streetName empty" << std::endl;
  //   }
  if (!new_town.city.empty() && new_town.nb > 0 &&
      !new_town.streetType.empty() && !new_town.streetName.empty())
    this->town.push_back(new_town);
  else
    std::cerr << backup << std::endl;
}

void				Exec::updateExecTown(std::vector<std::string> getTown)
{
  unsigned int			i;
  unsigned int			j;

  i = 0;
  while (i < town.size())
    {
      j = 0;
      if (getTown.size() != town[i].city.size())
	{
	  town.erase(town.begin() + i);
	  i = i - 1;
	}
      else
	{
	  while (j < town[i].city.size())
	    {
	      if (strcasecmp(town[i].city[j].c_str(), getTown[j].c_str()) != 0)
		{
		  town.erase(town.begin() + i);
		  i = i - 1;
		  break ;
		}
	      j = j + 1;
	    }
	}
      i = i + 1;
    }
}

int				Exec::start()
{
  std::vector<std::string>	townGet;

  completionTown.Init(town);
  townGet = completionTown.autoGetTown(town);
  unsigned int i = 0;

  // Display
  std::cout << "TownGetBy autoGetTown: ";
  while (i < townGet.size())
    {
      std::cout << townGet[i] << " ";
      i += 1;
    }
  std::cout << std::endl;
  updateExecTown(townGet);
  i = 0;
  unsigned int j;
  while (i < town.size())
    {
      j = 0;
      while (j < town[i].city.size())
	{
	  std::cout << town[i].city[j] << " ";
	  j = j + 1;
	}
      std::cout << std::endl;
      i = i + 1;
    }
  completionStreet.Init(town);
  townGet = completionStreet.autoGetTown(town);
  // End display
  return (0);
}
