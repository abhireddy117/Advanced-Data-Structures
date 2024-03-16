#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }



        //
        // Your code goes here
        //
      // finding user savage1
     // Creating a new map with key as userName and value as TwitterData as object

    map<string, TwitterData> userMap;
    

    for (int i = 0; i < 5; i++) {
        userMap[twitter_data[i].getUserName()] = twitter_data[i];
    }

    cout << "printing key value pairs: " << endl;
    for (auto pair : userMap) {
        cout << pair.first << endl
            << pair.second.print() << endl << endl;
    }

    if (userMap.find("savage1") != userMap.end()) {
        cout << userMap["savage1"].print() << endl;
    }
    else {
        cout << "svagage1 not found!" << endl;
    }

    // search based on username
    string username;
    cout << "\nenter username to search in the records: ";
    cin >> username;
    auto it = userMap.find(username);
    if ( it != userMap.end()) {
        cout << username << ": " << userMap[username].print() << endl;
    }
    else {
        cout << username << " not found!" << endl;
    }
    userMap.erase(it);
    

    cout << "Printing key value pairs: " << endl;
    for (auto pair : userMap) {
        cout << pair.first << endl
            << pair.second.print() << endl << endl;
    }


    //**********************************************************************//
    // Email
    map<string, TwitterData> emailMap;

   
    for (int i = 0; i < 5; i++) {
        emailMap[twitter_data[i].getEmail()] = twitter_data[i];
    }

    cout << "Printing key value pairs: " << endl;
    for (auto pair : emailMap) {
        cout << pair.first << endl
            << pair.second.print() << endl << endl;
    }

    if (emailMap.find("kat@gmail.com") != emailMap.end()) {
        cout << emailMap["kat@gmail.com"].print() << endl;
    }
    else {
        cout << "kat@gmail.com not found!" << endl;
    }

    
    string user_email;
    cout << "\nEnter Email to search in the records: ";
    cin >> user_email;
    auto it_1 = emailMap.find(user_email);
    if (it_1 != emailMap.end()) {
        cout << user_email << ": " << emailMap[user_email].print() << endl;
    }
    else {
        cout << user_email << " not found!" << endl;
    }
    emailMap.erase(it_1);


    cout << "Printing key value pairs: " << endl;
    for (auto pair : emailMap) {
        cout << pair.first << endl
            << pair.second.print() << endl << endl;
    }


    return 0;
}