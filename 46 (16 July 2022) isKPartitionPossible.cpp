bool isKPartitionPossible(int a[], int n, int k)
    {
        if (k == 1) {
            return true;
        } else if (n < k) {
            return false;
        } else {
            int sum = 0;
            for (int i=0; i<n; i++) {
                sum += a[i];
            }
            if (sum % k != 0) {
                return false;
            } else {
                int i = 0, j = n - 1, target = sum / k;
                sort(a, a+n);
                while (i < j) {
                    if (a[i] + a[j] > target) {
                        if (a[j] == target) {
                            j--;
                        } else {
                            return false;
                        }
                    } else {
                        i++;
                        j--;
                    }
                }
                return true;
            }
        }
    }
