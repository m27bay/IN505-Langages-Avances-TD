#include <iostream>

#include <ctime>

void printCalendar( std::string month, std::string dayWeek[7], int year, std::string startDay )
{
  std::cout << "------------------------------" << std::endl;
  std::cout << "         ";
  std::cout << month;
  std::cout << " , ";
  std::cout << year << std::endl;
  std::cout << "------------------------------" << std::endl;
  for( int i = 0; i < 7; i++)
  {
    std::cout << " ";
    std::cout << dayWeek[i];
  }
  std::cout << "" << std::endl;
}

std::string startWeek ( std::string dayWeek[7], int day, int pos )
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
  std::cout << "\n         Calendar" << std::endl;

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

  printCalendar( months[ltm->tm_mon], dayWeek, 1900 + ltm->tm_year, startWeek ( dayWeek, day, ltm->tm_wday ) );

  return 0;
}
