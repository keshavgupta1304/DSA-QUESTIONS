/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    if (s2.length < s1.length) {
        return false;
    }

    let freq_s1 = new Map(); // map to store frequency count of characters in s1
    let freq_s2 = new Map(); // map to store frequency count of characters in s2 for a window size equal to s1.length

    // Initialization
    for (let i = 0; i < s1.length; i++) {
        freq_s1.set(s1[i], (freq_s1.get(s1[i]) || 0) + 1);
        freq_s2.set(s2[i], (freq_s2.get(s2[i]) || 0) + 1);
    }

    // Initial comparison
    if (mapsAreEqual(freq_s1, freq_s2)) {
        return true;
    }

    for (let i = s1.length; i < s2.length; i++) {
        let ch_out = s2[i - s1.length]; // character to remove
        if (freq_s2.get(ch_out) === 1) {
            freq_s2.delete(ch_out);
        } else {
            freq_s2.set(ch_out, freq_s2.get(ch_out) - 1);
        }

        let ch_in = s2[i]; // character to add
        freq_s2.set(ch_in, (freq_s2.get(ch_in) || 0) + 1);

        // Check final condition
        if (mapsAreEqual(freq_s1, freq_s2)) {
            return true;
        }
    }

    return false;
};

/**
 * Helper function to check if two maps are equal
 * @param {Map} map1
 * @param {Map} map2
 * @return {boolean}
 */
function mapsAreEqual(map1, map2) {
    if (map1.size !== map2.size) {
        return false;
    }
    for (let [key, val] of map1) {
        if (val !== map2.get(key)) {
            return false;
        }
    }
    return true;
}
