// 180410HeadFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <stdio.h>  
//#include <stdlib.h>  
#include <Windows.h>
#include<io.h>
#include<iostream>  
#include<vector>  
#include <fstream>    
#include <iterator>
#include <cassert>
#include <string> 
#include "EnumFiles.h"
#include <fstream>
#include <sstream>

using namespace std;



int main()
{
	CEnumFiles enumFiles;
	enumFiles.findfile("C:\\Code\\UCR_TS_Archive_2015");
	for (int i = 0; i<enumFiles.res.size(); i++){
		
		if (i % 3 != 0) {
			cout << enumFiles.res[i] << endl;
			//enumFiles.countColumnRowNumber(enumFiles.res[i]);
		}
		
	}

	system("pause");
	return 0;
}

