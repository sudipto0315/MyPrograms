#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
struct cmp{
    bool operator()(pair <int,string>a,pair<int,string>b) const{
        if(a.first>b.first) return 1;
        if(a.first<b.first) return 0;
        return a.second<b.second; // if rating is same then sort by food name (lexicographically)
    }
};

class FoodRatings {
public:
    // cuisine -> (food, rating) cuisine to rating and food
    unordered_map<string,set<pair<int,string>,cmp>>cuisineToRatingAndFood;
    // food -> (cuisine, rating) food to cuisine and rating
    unordered_map<string,pair<string,int>>foodToCuisineAndRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            foodToCuisineAndRating[foods[i]]={cuisines[i],ratings[i]};
            cuisineToRatingAndFood[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=foodToCuisineAndRating[food].first;
        int oldRating=foodToCuisineAndRating[food].second;
        cuisineToRatingAndFood[cuisine].erase({oldRating,food});
        cuisineToRatingAndFood[cuisine].insert({newRating,food});
        foodToCuisineAndRating[food]={cuisine,newRating};
    }
    
    string highestRated(string cuisine) {
        return (*cuisineToRatingAndFood[cuisine].begin()).second;
    }
};

int main() {
    vector<string> foods = {"kimchi","miso","sushi","moussaka","ramen","bulgogi"};
    vector<string> cuisines = {"Korean","Japanese","Japanese","Greek","Japanese","Korean"};
    vector<int> ratings = {9,12,8,15,14,7};
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
    string s = obj->highestRated("Korean"); // kimchi
    cout << s << endl;
    s = obj->highestRated("Japanese"); // ramen
    cout << s << endl;
    obj->changeRating("sushi", 16); // sushi rating changed from 8 to 16
    string param_2 = obj->highestRated("Japanese");
    cout << param_2 << endl;
    obj->changeRating("ramen", 16); // ramen rating changed from 14 to 16
    param_2 = obj->highestRated("Japanese");
    cout << param_2 << endl;
    return 0;
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */