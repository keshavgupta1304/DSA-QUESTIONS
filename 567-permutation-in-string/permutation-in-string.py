class Solution(object):
    def checkInclusion(self, s1, s2):
        if len(s2) < len(s1):
            return False

        # Initialize the frequency counters
        freq_s1 = Counter(s1)
        freq_s2 = Counter(s2[:len(s1)])

        # Initial comparison
        if freq_s1 == freq_s2:
            return True

        for i in range(len(s1), len(s2)):
            ch_out = s2[i - len(s1)]  # character to remove
            ch_in = s2[i]  # character to add

            # Update the frequency counter for the outgoing character
            if freq_s2[ch_out] == 1:
                del freq_s2[ch_out]
            else:
                freq_s2[ch_out] -= 1

            # Update the frequency counter for the incoming character
            freq_s2[ch_in] += 1

            # Check if the frequency counters are equal
            if freq_s1 == freq_s2:
                return True

        return False
        