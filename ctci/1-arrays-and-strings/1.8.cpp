/**
 * Assume you have a method isSubstring which checks if one word is a substring of another. 
 * Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only 
 * one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
 */

bool isRotation(string s1, string s2) {
    //s2 is rotated one
    //s1 is normal
    
    if(s2.length() == s1.length() && s1.length() > 0) {
        return isSubstring(s1, s2+s2);
    }
}