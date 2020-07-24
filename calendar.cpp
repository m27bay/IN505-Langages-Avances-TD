#include <iostream>

#include <ctime>

void printMonth( std::string month, std::string dayWeek[7], int year, std::string startDay, int numDay, int posDay )
{
  for( int i = 0; i < 7; i++)
  {
    std::cout << " ";
    std::cout << dayWeek[i];
  }
  std::cout << "" << std::endl;

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
      std::cout << "0" << i+1;
    else
      std::cout << i+1;

    posDayTmp++;
    tmpDay = dayWeek[posDayTmp];
  }
}

int posDay( std::string day, std::string dayWeek[7] )
{
  for( int i = 0; i < 7; i++ )
  {
    if( day.compare( dayWeek[i] ) == 0 )
      return i;
  }
}

void printCalendar( std::string months[12], int numMonth, std::string dayWeek[7], int year, std::string startDay, int posDay )
{
  std::cout << "\n         Calendar" << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "         ";
  std::cout << months[numMonth];
  std::cout << " , ";
  std::cout << year << std::endl;
  std::cout << "------------------------------" << std::endl;

  if( numMonth%2 == 0 || months[numMonth].compare("Aug") == 0 )
    printMonth( months[numMonth], dayWeek, year, startDay, 31, posDay);
  else if( months[numMonth].compare("Feb") == 0 && year%4 == 0 )
    printMonth( months[numMonth], dayWeek, year, startDay, 29, posDay);
  else if( months[numMonth].compare("Feb") == 0 && year%4 != 0 )
    printMonth( months[numMonth], dayWeek, year, startDay, 28, posDay);
  else
    printMonth( months[numMonth], dayWeek, year, startDay, 30, posDay);

  std::cout << "" << std::endl;
}

std::string startWeek( std::string dayWeek[7], int day, int pos )
{
  int tmp(0);
  if( day > 7 )
    tmp = day%7;
  else
    tmp = day;

  std::string dayTmp = dayWeek[ pos - tmp + 1];
  return dayTmp;
}

int main(int argc, char const *argv[])
{
  std::string dayWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

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

  std::string start = startWeek( dayWeek, day, ltm->tm_wday );
  printCalendar( months, ltm->tm_mon, dayWeek, 1900 + ltm->tm_year, start, posDay( start, dayWeek ) );

  return 0;
}
