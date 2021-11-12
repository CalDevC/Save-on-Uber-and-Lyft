
#include "TripOverview.cpp"
#include <string>
#include <iostream>

int main() {
	Trip a = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1544952607890", 5.0, false);
	Trip b = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1543805278271", 15.0, false);
	Trip c = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1545098110455", 10.0, false);
	Trip d = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1545098110455", 25.0, false);
	Trip e = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1545098110455", 20.0, false);
	Trip f = Trip("424553bb-7174-41ea-aeb4-fe06d4f4b9d7", "Haymarket Square", "North Station", "Lyft", "1544952607890", 10.0, false);

   std::vector<Trip> data;
   data.push_back(a);
   data.push_back(b);
   data.push_back(c);
   data.push_back(d);
   data.push_back(e);
   data.push_back(f);

   TripOverview overview = TripOverview(a, data);

   overview.calcCheapestTime(data);
}
