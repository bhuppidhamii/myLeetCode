class Solution {
  public:
    int derangeCount(int n) {
  
  // Base cases
  if (n == 1) return 0;
  if (n == 2) return 1;

  // f(n) = (n-1)[f(n-1) + f(n-2)]
  return (n - 1) * (derangeCount(n - 1) + 
                        derangeCount(n - 2));
}

};