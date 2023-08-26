// SPDX-License-Identifier: MIT
pragma solidity ^0.5.0;

contract BenchmarkBubbleSort {
    function BenchmarkbubbleSort()
        public
        pure
        returns (uint[] memory sortedArr)
    {
        uint8[10] memory arr = [23, 8, 56, 42, 91, 17, 33, 5, 72, 10];
        uint n = arr.length;
        sortedArr = new uint[](n);
        for (uint i = 0; i < n; i++) {
            sortedArr[i] = arr[i];
        }
        for (uint i = 0; i < n - 1; i++) {
            for (uint j = 0; j < n - i - 1; j++) {
                if (sortedArr[j] > sortedArr[j + 1]) {
                    (sortedArr[j], sortedArr[j + 1]) = (
                        sortedArr[j + 1],
                        sortedArr[j]
                    );
                }
            }
        }
        return sortedArr;
    }
}
