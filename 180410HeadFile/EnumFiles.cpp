#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <Windows.h> 
#include<io.h>
#include<iostream>  
#include<vector>  
#include <fstream> 
#include <sstream>
#include <iterator>  
#include <string> 
#include "EnumFiles.h"
#include <cassert>

using namespace std;

#define MAX_PATH 1024

vector<string> CEnumFiles::listdir(const string &path)
 {
	 string dir = path;
	 vector<string> s;
	 _finddata_t fileDir;
	 long lfDir;

	 if ((lfDir = _findfirst(dir.c_str(), &fileDir)) == -1l){
		 //printf("No file is found\n");
	 }
	 else {
		 do {

			 string str(fileDir.name);
			 if (str.find('.') == -1)
				 s.push_back(str);

		 } while (_findnext(lfDir, &fileDir) == 0);
	 }
	 _findclose(lfDir);
	 return s;
 }

 void CEnumFiles::findfile(const string &str)
 {
	 string s = str;
	 vector<string> tmp = listdir(s + "\\*");
	 for (int i = 0; i<tmp.size(); i++)
	 {
		 string temp = s + "\\" + tmp[i];
		 res.push_back(temp);
		 findfile(temp);
	 }
 }

 //************************************
 // Method:    countColumnRowNumber
 // @date : 2018/4/10 16:50
 // @author :   Ruidong Xue
 //************************************

 bool CEnumFiles::countColumnRowNumber(const string& file_name) {
	 //bool getFileStream(const string& file_name, T(&mg_input_data)[ROW][COLUMN]) {

	 //T* mp_pointer = *mg_input_data;
	 /*T* mp_pointer = &mg_input_data[0][0];*/
	 string fs_row_string;
	 string fs_row_number;

	 /*for (int i = 0; i < ROW; i++) {
	 for (int j = 0; j <= COLUMN; j++) {
	 mg_input_data[i][j] = NULL;
	 }
	 }*/

	 ifstream file_stream = ifstream(file_name);
	 assert(file_stream);
	 /*if (!file_stream) {
	 cout << "Can't open file " << file_name << " !!!!";
	 return false;
	 }*/

	 int row_count = 0;
	 int column_count = 0;
	 int column_number = 0;

	 while (!file_stream.eof())
	 {
		 row_count++;
		 file_stream >> fs_row_string;
		 stringstream sstr(fs_row_string);

		 while (getline(sstr, fs_row_number, ',')) {
			 stod(fs_row_number);
			 if (column_number == 0) {
				 column_count++;
			 }
		 }
		 column_number = column_count;
	 }

	 file_stream.close();

	 cout << row_count << ", " << column_number << endl;
	 return true;
 }
