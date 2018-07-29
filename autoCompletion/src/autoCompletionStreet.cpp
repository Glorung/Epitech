//
// autoCompletion.cpp for autocompletion in /home/glorung/Piscine/autoCompletion/src
//
// Made by
// Login   <glorung@epitech.net>
//
// Started on  Tue Jul  5 09:06:35 2016
// Last update Wed Jul  6 15:43:29 2016 
//

#include	<cstring>
#include	"autocompletion.hpp"

int		AutoCompletionStreet::IsInStreetName(std::string town)
{
  unsigned int	i;

  i = 0;
  if (getTown.size() == 0)
    return (0);
  while (i < getTown.size())
    {
      if (strcasecmp(town.c_str(), getTown[i].name.c_str()) == 0)
	{
	  getTown[i].size += 1;
	  return (1);
	}
      i = i + 1;
    }
  return (0);
}

void		AutoCompletionStreet::Init(std::vector<Town> town)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  while (i < town.size())
    {
      j = 0;
      while (j < town[i].streetName.size())
	{
	  if (!IsInStreetName(town[i].streetName[j]))
	    {
	      City	new_streetName;

	      new_streetName.name = town[i].streetName[j];
	      new_streetName.size = 1;
	      getTown.push_back(new_streetName);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  unsigned int	end;

  end = 0;
  while (end == 0)
    {
      end = 1;
      i = 1;
      while (i < getTown.size())
	{
	  if (getTown[i - 1].size < getTown[i].size)
	    {
	      City		tmp;

	      tmp = getTown[i - 1];
	      getTown[i - 1] = getTown[i];
	      getTown[i] = tmp;
	      end = 0;
	    }
	  i = i + 1;
	}
    }
  end = 0;
  while (end == 0)
    {
      end = 1;
      i = 1;
      while (i < getTown.size())
	{
	  if (getTown[i - 1].size == getTown[i].size)
	    {
	      if (strcasecmp(getTown[i - 1].name.c_str(), getTown[i].name.c_str()) > 0)
		{
		  City		tmp;

		  tmp = getTown[i - 1];
		  getTown[i - 1] = getTown[i];
		  getTown[i] = tmp;
		  end = 0;
		}
	    }
	  i = i + 1;
	}
    }
}

// display

void		AutoCompletionStreet::displayChoice(std::vector<char> choice)
{
  unsigned int	i;

  i = 0;
  while (i != 4 && i < (choice.size() - 1))
    {
      std::cout << "{" << get << choice[i] << "} ";
      i = i + 1;
    }
  std::cout << "{" << get << choice[i] << "}" << std::endl;
}

// autocompletion

int			AutoCompletionStreet::checkEndWord()
{
  unsigned int			i;
  std::vector<char>		choice;

  i = 0;
  while (i != this->getTown.size())
    {
      if (! (pos < getTown[i].name.length()))
	{
	  std::cout << getTown[i].name << std::endl;
	  get = toUpper(getTown[i].name);
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}
std::vector<char>	AutoCompletionStreet::getChoice()
{
  unsigned int			i;
  std::vector<char>		choice;

  i = 0;
  while (i != this->getTown.size())
    {
      if (pos < getTown[i].name.length() &&
	  !checkVector_char(choice, getTown[i].name[pos]))
	choice.push_back(getTown[i].name[pos]);
      i = i + 1;
    }
  i = 0;
  if (choice.size() == 1)
    {
      while (i != this->getTown.size())
	{
	  if (pos < getTown[i].name.length() &&
	      !checkVector_char(choice, getTown[i].name[pos]))
	    get = toUpper(get = getTown[i].name);
	  i = i + 1;
	}
    }
  return (choice);
}

void			AutoCompletionStreet::updateVector()
{
  unsigned int		i;

  i = 0;
  while (i < getTown.size())
    {
      if (strncasecmp(get.c_str(), getTown[i].name.c_str(), get.length()))
	{
	  getTown.erase(getTown.begin() + i);
	  i = i - 1;
	}
      i = i + 1;
    }
}

char				AutoCompletionStreet::getInput(int word_end, int size)
{
  std::string			entry;
  int				getNbr;

  // size
  size = size;
  entry = getEntry();
  if (entry == "ABORT")
    exit(0);
  if (entry.length() != 1)
    {
      std::cerr << "Invalid argument" << std::endl;
      return (getInput(word_end, size));
    }
  if (word_end == 0 && entry[0] >= '0' && entry[0] <= '9')
    {
      std::cerr << "Invalid argument" << std::endl;
      return (getInput(word_end, size));
    }
  else if (word_end == 1 && entry[0] >= '0' && entry[0] <= '9')
    {
      getNbr = atoi(entry.c_str());
      if (getNbr >= 1 && getNbr <= size)
	return ((char)(getNbr));
      else
	{
	  std::cerr << "Invalid argument" << std::endl;
	  return (getInput(word_end, size));
	}
    }
  if (entry[0] >= 'a' && entry[0] <= 'z')
    entry[0] += -32;
  return (entry[0]);
}

bool				AutoCompletionStreet::streetNameExist(std::vector<Town> thisVector,
							  std::vector<std::string> town)
{
  unsigned int				i;

  i = 0;
  if (thisVector.size() == 0)
    return (false);
  while (i < thisVector.size())
    {
      if (vectorCmp(thisVector[i].streetName, town) == 0)
	return (true);
      i = i + 1;
    }
  return (false);
}

std::vector<Town>		AutoCompletionStreet::removeUselessTown(std::vector<Town> town)
{
  unsigned int			i;
  std::vector<Town>		newTown;

  i = 0;
  while (i < town.size())
    {
      if (newTown.empty())
	newTown.push_back(town[i]);
      else if (streetNameExist(newTown, town[i].streetName) == false)
	newTown.push_back(town[i]);
      i = i + 1;
    }
  return (newTown);
}

// To keep

void				AutoCompletionStreet::displayFinalChoice(std::vector<std::vector<std::string> > & finalChoice)
{
  unsigned int			i;
  unsigned int			j;
  unsigned int			nbr;

  i = 0;
  nbr = 1;
  toLower(get);
  while (i < finalChoice.size() - 1)
    {
      j = 1;
      std::cout << "{";
      if (finalChoice[i].size() == 1)
	std::cout << nbr++ << " :  " << toUpper(finalChoice[i][0]) << "} ";
      else
	{
	  if (strcmp(get.c_str(), finalChoice[i][0].c_str()) == 0)
	    std::cout << nbr++ << " :  " << toUpper(finalChoice[i][0]) << " ";
	  else
	    std::cout << nbr++ << " :  " << finalChoice[i][0] << " ";
	  while (j < finalChoice[i].size() - 1)
	    {
	      if (strcmp(get.c_str(), finalChoice[i][j].c_str()) == 0)
		std::cout << toUpper(finalChoice[i][j]) << " ";
	      else
		std::cout << finalChoice[i][j] << " ";
	      j = j + 1;
	    }
	  if (strcmp(get.c_str(), finalChoice[i][j].c_str()) == 0)
	    std::cout << toUpper(finalChoice[i][j]) << "} ";
	  else
	    std::cout << finalChoice[i][j] << "} ";
	}
      i = i + 1;
    }
  j = 1;
  std::cout << "{";
  if (finalChoice[i].size() == 1)
      std::cout << nbr++ << " :  " << toUpper(finalChoice[i][0]) << "} ";
  else
    {
      if (strcmp(get.c_str(), finalChoice[i][0].c_str()) == 0)
	std::cout << nbr++ << " :  " << toUpper(finalChoice[i][0]) << " ";
      else
	std::cout << nbr++ << " :  " << finalChoice[i][0] << " ";
      while (j < finalChoice[i].size() - 1)
	{
	  if (strcmp(get.c_str(), finalChoice[i][j].c_str()) == 0)
	    std::cout << toUpper(finalChoice[i][j]) << " ";
	  else
	    std::cout << finalChoice[i][j] << " ";
	  j = j + 1;
	}
      if (strcmp(get.c_str(), finalChoice[i][j].c_str()) == 0)
	std::cout << toUpper(finalChoice[i][j]) << "}";
      else
	std::cout << finalChoice[i][j] << "}";
    }
  i = i + 1;
  std::cout << std::endl;
  get = toUpper(get);
}

std::vector<std::vector<std::string> >		AutoCompletionStreet::getFinalChoice(std::vector<Town> town)
{
  unsigned int		i;
  unsigned int		j;
  std::vector<std::vector<std::string> >		returnV;

  i = 0;
  toLower(get);
  while (i < town.size())
    {
      j = 0;
      while (j < town[i].streetName.size())
	{
	  if (strcmp(town[i].streetName[j].c_str(), get.c_str()) == 0)
	    {
	      returnV.push_back(town[i].streetName);
	      break;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  if (returnV.empty() || returnV[0].empty())
    {
      std::cerr << "Unknown Adress" << std::endl;
      exit(ERROR_V);
    }
  get = toUpper(get);
  return (returnV);
}

std::vector<std::string>	AutoCompletionStreet::autoGetTown(std::vector<Town> town)
{
  char				input;
  std::vector<char>		choice;
  std::vector<std::vector<std::string> >	finalChoice;

  int				word_end;
  int				end_autocomplete;

  town = removeUselessTown(town);
  while (getTown.size() != 1)
    {
      word_end = 0;
      // Autocompletion
      end_autocomplete = 0;
      while (!end_autocomplete)
	{
	  end_autocomplete = 1;

	  if (checkEndWord() == -1)
	    word_end = 1;
	  else
	    {
	      if ((choice = getChoice()).empty())
		{
		  if (getFinalChoice(town).empty())
		    {
		      std::cerr << "Unknown Adress" << std::endl;
		      exit(ERROR_V);
		    }
		  else
		    {
		      return (getFinalChoice(town)[0]);
		    }
		}
	      else if (choice.size() == 1)
		{
		  end_autocomplete = 0;
		  pos += 1;
		  get.push_back(choice[0] - 32);
		  updateVector();
		}
	    }
	}
      if (word_end == 1)
	{
	  finalChoice = getFinalChoice(town);
	  if (finalChoice.size() == 1)
	    return (finalChoice[0]);
	}

      // Affichage
      if (word_end == 0)
	displayChoice(choice);
      else
	{
	  displayFinalChoice(finalChoice);
	}

      // Recuperation de l'entree utilisateur
      if (word_end == 0)
	input = getInput(word_end, 0);
      if (word_end == 1)
	input = getInput(word_end, finalChoice.size());

      // Utilisation de l'input
      if (input >= 'A' && input <= 'Z')
	{
	  pos += 1;
	  get += input;
	  updateVector();
	}
      else
	{
	  std::cout << "get input " << (int)(input) << std::endl;
	  return (finalChoice[input - 1]);
	}
    }
  get = toUpper(getTown[0].name);
  return (getFinalChoice(town)[0]);
}
