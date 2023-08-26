function bubbleSort(arr) {
  var n = arr.length
  for (var i = 0; i < n - 1; i++) {
    for (var j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        var aux = arr[j]
        arr[j] = arr[j + 1]
        arr[j + 1] = aux
      }
    }
  }
}
const testArray = [23, 8, 56, 42, 91, 17, 33, 5, 72, 10]

console.time('OrdenamientoBurbuja')
bubbleSort(testArray)
console.timeEnd('OrdenamientoBurbuja')
