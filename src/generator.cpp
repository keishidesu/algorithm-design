#ifdef BUILD_GENERATOR

#include "generator.h"
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

Generator::Generator() {

  value = 10;

  string* setA = new string[100];
  string* setB = new string[100000];
  string* setC = new string[500000];

  //define a constant random seed
  srand(0);
  for(int i = 0; i < 100; i++)
    setA[i] = getRandomEmail();
  
  printArray(setA, 100, "SetA");

  for(int i = 0; i < 100000; i++)
    setB[i] = getRandomEmail();

  printArray(setB, 100000, "SetB");

  for(int i = 0; i < 500000; i++)
    setC[i] = getRandomEmail();

  printArray(setC, 500000, "SetC");
}

string Generator::getRandomName (int length){
  string name;

  name.reserve(length);

  for (int i = 0; i < length; i++)
    name += alphanum[rand() % (sizeof(alphanum) - 1)];

  return name;
}

string Generator::getRandomDomain (int length) {
  string domain;
  string suffix[] = {".com", ".my", ".org"};

  domain.reserve(length);

  for(int i = 0; i < length; i++)
    domain += alphanum[rand() % (sizeof(alphanum) - 11) + 9];

  domain += suffix[rand() % (sizeof(suffix)/sizeof(suffix[0]))];

  return domain;
}

string Generator::getRandomEmail () {
  return getRandomName(4) + "." + getRandomName(5) + "@" + getRandomDomain(4);
}

template <typename T>
void Generator::printArray (T A[], int n, string name) {
  ofstream writeFile;
  writeFile.open(name + ".txt");
  for (int i = 0; i < n; i++ )
    writeFile << A[i] << endl;
  writeFile.close();
}

#endif
