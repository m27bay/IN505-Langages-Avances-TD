#include <iostream>

#include <ctime>

/**
  * Print one month
  * month : actually month name
  * dayWeek[] : table with days names
  * years : actually year
  * startDay : month day start
  * numDay : actually day number
  * posDay : day position in the table ( start at Sunday )
  */
void printMonth( std::string month, std::string dayWeek[7], int year, std::string startDay, int numDay, int posDay, int dayNow )
{
  // Print day name
  for( int i = 0; i < 7; i++)
  {
    std::cout << " ";
    std::cout << dayWeek[i];
  }
  std::cout << "" << std::endl;

  // Found good place day
  for( int i = 0; i < 7; i++)
  {
    if( dayWeek[i].compare(startDay) != 0 )
    {
      std::cout << "  ";
    }
    else
      break;
    std::cout << "  ";
  }

  // Write day number
  std::string tmpDay = startDay;
  int posDayTmp = posDay;

  for( int i = 0; i < numDay; i++ )
  {
    std::cout << "  ";
    if( tmpDay.compare("Sat") == 0 )
    {
      if( i+1 < 10 )
        std::cout << "0" << i+1;
      else
        std::cout << i+1;

      std::cout << "" << std::endl;
      tmpDay = "Sun";
      posDayTmp = 0;

      continue;
    }

    if( i+1 < 10 )
    {
      if( i+1 == dayNow )
        std::cout << "\033[1;34m" << "0" << i+1 << "\033[0m";
      else
        std::cout << "0" << i+1;
    }
    else
    {
      if( i+1 == dayNow )
        std::cout << "\033[1;34m" << i+1 << "\033[0m";
      else
        std::cout << i+1;
    }

    posDayTmp++;
    tmpDay = dayWeek[posDayTmp];
  }
}

/**
  * Found day position in the name day table
  * day : name day
  * dayWeek[] : name day table
  */
int posDay( std::string day, std::string dayWeek[7] )
{
  for( int i = 0; i < 7; i++ )
  {
    if( day.compare( dayWeek[i] ) == 0 )
      return i;
  }
}

/**
  * Print calendar
  * months[] : month name table
  * numMonth : month number
  * dayWeek[] : name day table
  * years : actually year
  * startDay : month day start
  * posDay : day position in the table ( start at Sunday )
  */
void printCalendar( std::string months[12], int numMonth, std::string dayWeek[7], int year, std::string startDay, int posDay, int dayNow )
{
  std::cout << "\n          Calendar" << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "         ";
  std::cout << months[numMonth];
  std::cout << " , ";
  std::cout << year << std::endl;
  std::cout << "------------------------------" << std::endl;

  if( numMonth%2 == 0 || months[numMonth].compare("Aug") == 0 )
    printMonth( months[numMonth], dayWeek, year, startDay, 31, posDay, dayNow);
  else if( months[numMonth].compare("Feb") == 0 && year%4 == 0 )
    printMonth( months[numMonth], dayWeek, year, startDay, 29, posDay, dayNow);
  else if( months[numMonth].compare("Feb") == 0 && year%4 != 0 )
    printMonth( months[numMonth], dayWeek, year, startDay, 28, posDay, dayNow);
  else
    printMonth( months[numMonth], dayWeek, year, startDay, 30, posDay, dayNow);

  std::cout << "" << std::endl;
}

/**
  *
  */
std::string startWeek( std::string dayWeek[7], int day, int pos )
{
  int tmp(0);
  if( day > 7 )
    tmp = day%7;
  else
    tmp = day;

  int tmp2 = pos - tmp + 1;
  std::string dayTmp;
  if( tmp2 >= 0 )
    dayTmp = dayWeek[ pos - tmp + 1];
  else
    dayTmp = dayWeek[ 7 + tmp2 ];
  return dayTmp;
}

/**
  *
  */
int randomMonth()
{
  srand((unsigned int)time(0));
  return rand()%12;
}

/**
  *
  */
int randomMday(std::string months[12], int randYear)
{
  srand((unsigned int)time(0));
  int randMonth = randomMonth();
  if( randMonth % 2 == 0 || months[randMonth].compare("Aug") == 0 )
    return rand()%31+1;
  else if( months[randMonth].compare("Feb") == 0 && randYear%4 == 0 )
    return rand()%29+1;
  else if( months[randMonth].compare("Feb") == 0 && randYear%4 != 0 )
    return rand()%28+1;
  else
    return rand()%30+1;
}

/**
  *
  */
void runApp()
{
  // Data base ( days, months )
  std::string dayWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  // Get current date/time
  time_t now = time(0);

  // Get date informations
  tm *ltm = localtime( &now );

  std::string start = startWeek( dayWeek, ltm->tm_mday, ltm->tm_wday );
  printCalendar( months, ltm->tm_mon, dayWeek, 1900 + ltm->tm_year, start, posDay( start, dayWeek ), ltm->tm_mday );
  std::cout << "" << std::endl;

  std::string choice = "unknown";
  do
  {
    std::cout << "Choice : \n > ";
    std::cin >> choice;

    if( choice.compare("next") == 0 || choice.compare("n") == 0 )
    {
      system("clear");
      printMonth( months, ltm->tm_mon + 1, dayWeek, 1900 + ltm->tm_year, start, )
    }
    else if( choice.compare("quit") !=0 && choice.compare("q") != 0 )
      std::cout << "Choice unknown" << std::endl;
  }
  while( choice.compare("quit") !=0 && choice.compare("q") != 0 );
  std::cout << "Exit" << std::endl;
}

/**
  *
  */
int main(int argc, char const *argv[])
{
  /*
  // Get current date/time
  time_t now = time(0);

  // Convert in a String
  char* date = ctime( &now );
  // std::cout << date << std::endl;

  tm *ltm = localtime( &now );
  // std::cout << "Year: " << 1900 + ltm->tm_year << std::endl;
  // std::cout << "Month: " << 1 + ltm->tm_mon << std::endl;
  // std::cout << "Day: " <<  ltm->tm_mday << std::endl;
  int day = ltm->tm_mday;

  // Day since sunday
  // std::cout << "Day: " << dayWeek[ltm->tm_wday] << std::endl;

  // std::cout << startWeek ( dayWeek, day, ltm->tm_wday ) << std::endl;
  */

  std::cout << "\033[1;31mred\033[0m" << std::endl;
  std::cout << "\033[1;34mblue\033[0m" << std::endl;

  runApp();

  return 0;
}
