class Solution {
  public String[] uncommonFromSentences(String s1, String s2) {
    HashMap<String, Integer> hm = new HashMap<>();

    for (String s : s1.split(" ")) {
      hm.put(s, hm.getOrDefault(s, 0) + 1);
    }
    for (String s : s2.split(" ")) {
      hm.put(s, hm.getOrDefault(s, 0) + 1);
    }

    ArrayList<String> ans = new ArrayList<>();
    for (String key : hm.keySet()) {
      if (hm.get(key) == 1) {
        ans.add(key);
      }
    }
    return ans.toArray(new String[0]);
  }
}