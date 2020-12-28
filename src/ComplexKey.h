#ifndef COMPLEXKEY_H
#define COMPLEXKEY_H

#include <string>

class ComplexKey {
  public:
    ComplexKey();
    ComplexKey(std::string email);
    unsigned long long int getNameA();
    unsigned long long int getNameB();
    unsigned long long int getNameDomain();
    int getTopLevelDomain();
    bool operator==(const ComplexKey& c);
    bool operator>(const ComplexKey& c);
    bool operator<(const ComplexKey& c);
    bool operator!=(const ComplexKey& c);
  private:
    unsigned long long int nameA;
    unsigned long long int nameB;
    unsigned long long int nameDomain;
    int topLevelDomain;
    unsigned long long int polynomialHash(std::string name); 
};

#endif
