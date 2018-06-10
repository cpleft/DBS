#ifndef _TRAVEL_H_
#define _TRAVEL_H_

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include "/usr/include/mysql/mysql.h"
using namespace std;

/* globle variables */
extern MYSQL conn;

int Conn_dbs();                      // connect to mysqlDBS.travel
void CloseConn();
int query(string s); 
int resv(string custName, string resvType, string keywd);

int travel_road(string customer_name);
int check_road(string customer_name);

#endif
