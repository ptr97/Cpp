#pragma once
#include <iostream>
#include <string>
#include "MyClass.h"
#include "MyException.h"

static int ReturnValueID;
void Fold1(MyClass myClass, const int level);
void Fold2(MyClass myClass, const int level);
void Fold3(MyClass myClass, const int level);
void MyTerminate();
