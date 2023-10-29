export default function permutation(str) {
    permutationHelper(str, "");
}

function permutationHelper(str, prefix) {
    if (str.length === 0) {
        console.log(prefix);
    } else {
        for (let i = 0; i < str.length; i++) {
            const rem = str.substring(0, i) + str.substring(i + 1);
            permutationHelper(rem, prefix + str.charAt(i));
        }
    }
}

// Example usage:
permutation("abc");

