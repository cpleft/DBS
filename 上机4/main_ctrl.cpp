#include "travel_system.hpp"

MYSQL conn;
int main(int argc, char* argv[]) {
  Conn_dbs();
  --argc; ++argv;
  int i = 0;
  while (argc > 0) {
    if (strcmp(argv[i], "-q") == 0) {
      query(argv[i+1]);
      i += 2; argc -= 2;
    }
    else if (strcmp(argv[i], "-r") == 0) {
      resv(argv[i+1], argv[i+2], argv[i+3]);
      i += 4; argc -= 4;
    }
    else cout << "Unknown argument \""<< argv[i] <<"\""<<endl;
  }
  CloseConn();
  return 0;
}


/* explaination:
usage:
travle [-q flight|bus|hotel|reservation] [-r custName resvType keywd] 

options:
  -q query about flight, bus, hotel, reservation.
  -r reserve flight, bus, hotel.
      custName: [a-z].
      resvType: 1 for flight, 2 for hotel, 3 for bus.
      keywd: flightNum or hotel location or bus location.
 */
