#pragma once
#ifndef ENUM_FILES
#define ENUM_FILES

#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <Windows.h> 
#include "EnumFiles.h"
#include<io.h>
#include<iostream>  
#include<vector>  
#include <fstream>    
#include <iterator>  
#include <string> 


using namespace std;

class CEnumFiles
{
private:
	vector<string> listdir(const string &path);
public:
	vector<string> res;
	void findfile(const string &str);
	bool countColumnRowNumber(const string& file_name);
};

#endif