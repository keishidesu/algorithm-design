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

  string* newSetA = new string[10];
  string* newSetB = new string[10];
  string* newSetC = new string[10];

  string* oldSetA = new string[10];
  string* oldSetB = new string[10];
  string* oldSetC = new string[10];

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

  // 10 items that cannot be found in each set
  for(int i = 0; i < 10; i++)
    newSetA[i] = getNewEmail(setA, newSetA);

  printArray(newSetA, 10, "NewSetA");

  for(int i = 0; i < 10; i++)
    newSetB[i] = getNewEmail(setB, newSetB);

  printArray(newSetB, 10, "NewSetB");

  for(int i = 0; i < 10; i++)
    newSetC[i] = getNewEmail(setC, newSetC);

  printArray(newSetC, 10, "NewSetC");

  // 10 items that can be found in each set
  for(int i = 0; i < 10; i++)
    oldSetA[i] = getOldEmail(setA, oldSetA);

  printArray(oldSetA, 10, "OldSetA");

  for(int i = 0; i < 10; i++)
    oldSetB[i] = getOldEmail(setB, oldSetB);

  printArray(oldSetB, 10, "OldSetB");

  for(int i = 0; i < 10; i++)
    oldSetC[i] = getOldEmail(setC, oldSetC);

  printArray(oldSetC, 10, "OldSetC");
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

string Generator::getNewEmail (string set[], string newset[]) {
  bool existed;
  string newEmail;

  do {
    existed = false;
    newEmail = getRandomEmail();
    for(int i = 0; i < sizeof(*set); i++) {
      if(set[i] == newEmail) {
        existed = true;
        break;
      }
    }
    for(int i = 0; i < sizeof(*newset); i++) {
      if(newset[i] == newEmail) {
        existed = true;
        break;
      }
    }
  } while(existed);
  return newEmail;
}

string Generator::getOldEmail (string set[], string oldset[]) {
  bool existed;
  string oldEmail;

  do {
    existed = false;
    oldEmail = set[rand() % sizeof(*set)];
    for (int i = 0; i < sizeof(*oldset); i++) {
      if(oldset[i] == oldEmail) {
        existed = true;
        break;
      }
    }
  } while(existed);

  return oldEmail;
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
