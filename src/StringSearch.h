#ifndef SRC_STRINGSEARCH_H_
#define SRC_STRINGSEARCH_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *
 * @param name1
 * @param name2
 * @returns the alteration of numbers so that name1 is name2
 */
int EditDistance(string name1,string name2);

/**
 *
 * @param name1
 * @param name2
 * @returns  name1 if exists, else returns string empty
 */
string VerifyValidName(string name1,string name2);


/* find the toSearch in text
 * @param text
 * @param toSearch
 * @returns the index where found the word else zero
 */
int kmp(string text, string toSearch);

/*
 * initializes the suffix vector
 * @param toSearch
 * @param prefix
 * @returns void
 */
void pre_kmp(string toSearch, vector<int> & prefix);



#endif
