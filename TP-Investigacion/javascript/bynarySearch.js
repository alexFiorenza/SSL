function binarySearch(arr, target) {
  let left = 0
  let right = arr.length - 1

  while (left <= right) {
    const mid = Math.floor((left + right) / 2)

    if (arr[mid] === target) {
      return mid // Se encontró el elemento, devuelve su índice
    } else if (arr[mid] < target) {
      left = mid + 1 // El elemento está a la derecha, ajusta el límite izquierdo
    } else {
      right = mid - 1 // El elemento está a la izquierda, ajusta el límite derecho
    }
  }

  return -1 // El elemento no se encontró en el array
}

const sortedArray = [5, 8, 10, 17, 23, 33, 42, 56, 72, 91]
const target = 17
console.time('binarySearch')
binarySearch(sortedArray, target)
console.timeEnd('binarySearch')
