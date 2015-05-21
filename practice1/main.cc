#include <Particle.h>
#include <Pion.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/** @mainpage Practice Project
 *  
 *  This project is made for little examples during the lecture. <br>
 *  <a href="https://github.com/KIT-CSD-WS14-15/LectureCode">Get back to the github repository.</a>
 */
int main()
{
  cout << "Dies ist ein Testprogramm für Collaborative Software Design. " << endl;

  /** Map for storing the decay tree. */
  map<string, vector<string> > decayMap;
  decayMap["B"] = {"D", "Pion"};
  decayMap["D"] = {"Kaon", "Pion", "Pion"};

  /** Container for the Particle objects.*/
  vector<Particle> particles;
  //Reserve enough space, that the container doesn't have to be reallocated at push_back.
  particles.reserve(20);
  particles.emplace_back("B");

  for (auto iter = particles.begin(); iter != particles.end(); iter++) {
    for (auto & name : decayMap[(*iter).getName()]) {
      particles.emplace_back(name);
      (*iter).addDaughter(particles.back());
    }
  }

  //Is the number of B daughters equal the number of total particles?
  cout << "Wir haben so viele Teilchen in unserem Baum: " << particles.size() << endl;
  cout << "Die Zahl der B Töchter ist: " << particles[0].getNDaughters()      << endl;

  //How many Pions are in the list?
  cout << "Die Zahl der Pionen ist: "
       << count(particles.begin(), particles.end(), s_pion)
       << endl;
}
