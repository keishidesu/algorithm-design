#include <iostream>
#include <chrono>

using namespace std;

static const char alphanum[] =
  "0123456789"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz";

string getRandomName (int length) {
  string name;

  name.reserve(length);

  for (int i = 0; i < length; i++)
    name += alphanum[rand() % (sizeof(alphanum) - 1)];

  return name;
}

string getRandomDomain (int length) {
  string domain;
  string suffix[] = {".com", ".my", ".org"};

  domain.reserve(length);

  for(int i = 0; i < length; i++)
    domain += alphanum[rand() % (sizeof(alphanum) - 11) + 9];

  domain += suffix[rand() % (sizeof(suffix)/sizeof(suffix[0]))];

  return domain;
}

string getRandomEmail () {
  return  getRandomName(4) + "." + getRandomName(5) + "@" + getRandomDomain(4);
}

template <typename T>
void printArray (T A[], int n) {
  for (int i = 0; i < n; i++)
    cout << A[i] <<endl;
  cout << endl;
}

using namespace std;

int main()
{
  string* setA = new string[100];
  string* setB = new string[100000];
  string* setC = new string[500000];

  srand(time(0));
  for(int i = 0; i < 100; i++)
    setA[i] = getRandomEmail();

  cout << "Set A: " << endl;
  printArray(setA, 100);

  for(int i = 0; i < 100000; i++)
    setB[i] = getRandomEmail();

  cout << "Set B: " << endl;
  printArray(setB, 100000);

  for(int i = 0; i < 500000; i++)
    setC[i] = getRandomEmail();

  cout << "Set C: " << endl;
  printArray(setC, 500000);

}
