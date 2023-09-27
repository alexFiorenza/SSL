// SPDX-License-Identifier: MIT
pragma solidity ^0.5.0;

contract BenchmarkBinarySearch {
    function BenchmarkbinarySearch() public pure returns (int) {
        uint8[10] memory arr = [5, 8, 10, 17, 23, 33, 42, 56, 72, 91];
        uint target = 17;
        int left = 0;
        int right = int(arr.length) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[uint(mid)] == target) {
                return mid;
            }

            if (arr[uint(mid)] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
}
