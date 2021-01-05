#include "ComplexKey.h"
#include <string>
#define TOTAL_COMBINATION 62;

ComplexKey::ComplexKey() {}

ComplexKey::ComplexKey(std::string email) {
  // abcd.12345@efgh.com
  nameA = polynomialHash(email.substr(0 , 4));
  nameB = polynomialHash(email.substr(5 , 5));
  nameDomain = polynomialHash(email.substr(11 , 4));

  std::string domain = email.substr(16 , 3);
  if (domain == "com") { topLevelDomain = 1; }
  if (domain == "my") { topLevelDomain = 2; }
  if (domain == "org") { topLevelDomain = 3; }
}

unsigned long long int ComplexKey::getNameA() { return nameA; }

unsigned long long int ComplexKey::getNameB() { return nameB; }

unsigned long long int ComplexKey::getNameDomain() { return nameDomain; }

int ComplexKey::getTopLevelDomain() { return topLevelDomain; }

unsigned long long int ComplexKey::polynomialHash(std::string name) {
  unsigned long long int result = 0;
  for(std::string::size_type i = 0; i < name.size(); ++i) {
    unsigned long long int p = 1;

    for (int j = 0; j < i; j++) {
      p*=TOTAL_COMBINATION;
    }
  
    char c = name[i];
    if (c >= '0' && c <= '9') {
      result+=(c - '0')*p;
    } else if (c >= 'A' && c <= 'Z') {
      result+=(c - 'A' + '9' - '0' + 1)*p;
    } else if (c >= 'a' && c <= 'z') {
      result+=(c - 'a' + '9' - '0' + 'Z' - 'A' + 2)*p;
    }
  }
  return result;
}

bool ComplexKey::operator==(const ComplexKey& c) {
  return 
    this->nameA == c.nameA &&
    this->nameB == c.nameB &&
    this->nameDomain == c.nameDomain &&
    this->topLevelDomain == c.topLevelDomain;
}

bool ComplexKey::operator>(const ComplexKey& c) {
  if (this->nameA > c.nameA) { return true; }
  if (this->nameA == c.nameA && this->nameB > c.nameB) { return true; }
  if (this->nameB == c.nameB && this->nameDomain > c.nameDomain) { return true; }
  if (this->nameDomain == c.nameDomain && this->topLevelDomain > c.topLevelDomain) { return true; }
  return false;
}

bool ComplexKey::operator<(const ComplexKey& c) {
  if (this->nameA < c.nameA) { return true; }
  if (this->nameA == c.nameA && this->nameB < c.nameB) { return true; }
  if (this->nameB == c.nameB && this->nameDomain < c.nameDomain) { return true; }
  if (this->nameDomain == c.nameDomain && this->topLevelDomain < c.topLevelDomain) { return true; }
  return false;
}

bool ComplexKey::operator!=(const ComplexKey& c) {
  return 
    this->nameA != c.nameA ||
    this->nameB != c.nameB ||
    this->nameDomain != c.nameDomain ||
    this->topLevelDomain != c.topLevelDomain;
}