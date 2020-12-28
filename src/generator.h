#ifdef BUILD_GENERATOR

#ifndef GENERATOR
#define GENERATOR

#include <string>

static const char alphanum[] =
  "0123456789"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz";

class Generator {
  public:
    Generator();
  private:
    std::string getNewEmail (std::string set[], std::string newset[]);
    std::string getOldEmail (std::string set[], std::string oldset[]);
    std::string getRandomName(int length);
    std::string getRandomDomain (int length);
    std::string getRandomEmail (std::string set[]);
    bool checkDuplication (std::string email, std::string set[]);
    template <typename T> void printArray (T A[], int n, std::string name);
};

#endif
#endif
