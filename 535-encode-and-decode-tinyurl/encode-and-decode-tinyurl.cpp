class Solution {
public:

    int n=0;
    map<string,string>mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl=longUrl+=n;
        n++;
        mp[shortUrl]=longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));