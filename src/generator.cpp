#ifdef BUILD_GENERATOR

#include "generator.h"
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>

using namespace std;

Generator::Generator() {

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
  srand(time(0));
  std::cout << "Generating set A with 100 data..." << std::endl;
  for(int i = 0; i < 100; i++)
    setA[i] = getRandomEmail(setA);
  
  std::cout << "Writing set A to SetA.txt..." << std::endl;
  printArray(setA, 100, "SetA");

  std::cout << "Generating set B with 100000 data..." << std::endl;
  for(int i = 0; i < 100000; i++)
    setB[i] = getRandomEmail(setB);

  std::cout << "Writing set B to SetB.txt..." << std::endl;
  printArray(setB, 100000, "SetB");

  std::cout << "Generating set C with 500000 data..." << std::endl;
  for(int i = 0; i < 500000; i++)
    setC[i] = getRandomEmail(setC);

  std::cout << "Writing set C to SetC.txt..." << std::endl;
  printArray(setC, 500000, "SetC");

  std::cout << "Generating set A non-existing search set..." << std::endl;
  // 10 items that cannot be found in each set
  for(int i = 0; i < 10; i++)
    newSetA[i] = getNewEmail(setA, newSetA);

  std::cout << "Writing set A search set to NewSetA.txt..." << std::endl;
  printArray(newSetA, 10, "NewSetA");

  std::cout << "Generating set B non-existing search set..." << std::endl;
  for(int i = 0; i < 10; i++)
    newSetB[i] = getNewEmail(setB, newSetB);

  std::cout << "Writing set B search set to NewSetB.txt..." << std::endl;
  printArray(newSetB, 10, "NewSetB");

  std::cout << "Generating set C non-existing search set..." << std::endl;
  for(int i = 0; i < 10; i++)
    newSetC[i] = getNewEmail(setC, newSetC);

  std::cout << "Writing set C search set to NewSetC.txt..." << std::endl;
  printArray(newSetC, 10, "NewSetC");

  std::cout << "Generating set A existing search set..." << std::endl;
  // 10 items that can be found in each set
  for(int i = 0; i < 10; i++)
    oldSetA[i] = getOldEmail(setA, oldSetA);

  std::cout << "Writing set A search set to OldSetA.txt..." << std::endl;
  printArray(oldSetA, 10, "OldSetA");

 std::cout << "Generating set C existing search set..." << std::endl;
  for(int i = 0; i < 10; i++)
    oldSetB[i] = getOldEmail(setB, oldSetB);

  std::cout << "Writing set A search set to OldSetA.txt..." << std::endl;
  printArray(oldSetB, 10, "OldSetB");

  std::cout << "Generating set C existing search set..." << std::endl;
  for(int i = 0; i < 10; i++)
    oldSetC[i] = getOldEmail(setC, oldSetC);

  std::cout << "Writing set A search set to OldSetA.txt..." << std::endl;
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

string Generator::getRandomEmail (string set[]) {
  string email = getRandomName(4) + "." + getRandomName(5) + "@" + getRandomDomain(4);
  return checkDuplication(email, set) ? getRandomEmail(set) : email;
}

string Generator::getNewEmail (string set[], string newset[]) {
  bool existed;
  string newEmail;

  do {
    existed = false;
    newEmail = getRandomEmail(newset);
    existed = checkDuplication(newEmail, set);
  } while(existed);
  return newEmail;
}

string Generator::getOldEmail (string set[], string oldset[]) {
  bool existed;
  string oldEmail;

  do {
    existed = false;
    oldEmail = set[rand() % sizeof(*set)];
    existed = checkDuplication(oldEmail, oldset);
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

bool Generator::checkDuplication (string email, string set[]) {
  for(int i = 0; i < sizeof(*set); i++) {
    if(set[i] == email) {
      return true;
    }
  }
  return false;
}

#endif
   