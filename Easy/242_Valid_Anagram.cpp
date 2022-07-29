// Solution 1:
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return !s.compare(t);
    }
};

// Solution 2 link: https://leetcode.com/problems/valid-anagram/discuss/2343266/Going-from-O(NlogN)-greater-O(N)
// Time Complexiity: O(NlogN)
// Space Complexity: O(N)
class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();
        
        for(int i = 0; i < s.length(); i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        
        for(int i = 0; i < t.length(); i++){
            if(map.containsKey(t.charAt(i)) == false) return false;
            if(map.get(t.charAt(i)) > 1) map.put(t.charAt(i), map.get(t.charAt(i)) - 1);
            else map.remove(t.charAt(i));
        }
        return map.size() == 0;
    }
}