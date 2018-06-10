/* This file implements functions which related to DataBase system. */
#include "travel_system.hpp"

int Conn_dbs() {
  mysql_init(&conn);
  if (!mysql_real_connect(&conn, "localhost", "root", "040400312", "travel", 0, NULL, CLIENT_FOUND_ROWS)) 
    { cout<<"Failed to connect dbs"<<endl; return -1; }
  /*--code--*/
  cout << "successfully connected!"<<endl;
  return 0;
}

void CloseConn() {
  mysql_close(&conn);
  return;
}

int query(string s){
  string sqlstr;
  if (s == "flight" || s == "flights") {
    sqlstr = "\
      select * from flight;\
      ";
  }
  else if (s == "bus" || s == "buses") {
    sqlstr = "\
      select * from bus;\
      ";
  }
  else if (s == "reservation" || s == "reservations") {
    sqlstr = "\
      select * from reservation;\
      ";
  }
  else if (s == "hotel" || s == "hotels") {
    sqlstr = "\
      select * from hotel;\
      ";
  }
  else if (s == "customer" || s == "customers") {
    sqlstr = "\
      select * from customer;\
      ";
  }
  else {
    cout << "invalid input! please try to input \"bus\" or\
\"flight\" or \"hotel\" or \"customer\"." <<endl;
    return -2;
  }
  MYSQL_RES* result = NULL;
  if (mysql_query(&conn, sqlstr.c_str()) == 0) {
    cout << "mysql_query() select data succeed" << endl;
		//一次性取得数据集  
		result = mysql_store_result(&conn);
		//取得并打印行数  
		int rowcount = mysql_num_rows(result);
		cout << "row count: " << rowcount << endl;
		//取得并打印各字段的名称  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i<fieldcount; i++)
		{
			field = mysql_fetch_field_direct(result, i);
      printf("%20s", field->name);
		}
		cout << endl;
		//打印各行  
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		while (NULL != row)
		{
			for (int i = 0; i<fieldcount; i++)
        printf("%20s", row[i]);
			cout << endl;
			row = mysql_fetch_row(result);
    }
  }
  else {
    cout << "mysql_query() select data failed" << endl;
    CloseConn();
    return -1;
  }
}

int resv(string custName, string resvType, string keywd){
  string sqlstr;
  sqlstr = "insert into reservation value"; 
  sqlstr += "(\"" + custName + "\"," + resvType;
  sqlstr += ",\"" + custName+resvType + "\",\"" + keywd;
  sqlstr += "\");";
  cout << sqlstr <<endl;

  if (mysql_query(&conn, sqlstr.c_str()) == 0) {
    cout << "successfully inserted!" <<endl;
    return 0;
  }
  else {
		cout << "failed to insert!" << endl;
    CloseConn();
		return -1;
  }
}








