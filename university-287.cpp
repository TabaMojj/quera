#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
                67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
                139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
                223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283,
                293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
                383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461,
                463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563,
                569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
                647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739,
                743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829,
                839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937,
                941, 947, 953, 967, 971, 977, 983, 991, 997};

int dds[] = {6, 9, 10, 15, 17, 18, 20, 21, 24, 25, 28, 29, 30, 32, 34, 35, 37, 39, 42,
             43, 47, 48, 49, 50, 51, 53, 55, 60, 62, 65, 66, 67, 68, 69, 70, 74, 76, 77,
             81, 82, 84, 86, 87, 91, 93, 94, 95, 101, 102, 103, 105, 108, 109, 110, 111,
             114, 116, 117, 120, 121, 122, 124, 125, 126, 127, 128, 129, 130, 131, 132,
             133, 134, 135, 136, 138, 139, 141, 142, 144, 145, 147, 150, 152, 154, 155,
             156, 158, 159, 164, 165, 166, 168, 169, 173, 174, 175, 176, 177, 178, 181,
             182, 184, 186, 187, 189, 190, 195, 196, 197, 198, 199, 200, 202, 203, 204,
             209, 210, 211, 215, 217, 218, 220, 221, 222, 226, 227, 228, 230, 231, 232,
             233, 237, 241, 242, 244, 250, 253, 254, 255, 256, 258, 259, 261, 263, 264,
             265, 267, 268, 270, 271, 272, 273, 274, 277, 285, 288, 289, 291, 292, 293,
             295, 297, 302, 304, 305, 307, 308, 309, 311, 312, 313, 317, 319, 321, 325,
             327, 328, 329, 330, 331, 332, 336, 337, 338, 339, 340, 346, 348, 350, 351,
             352, 353, 355, 357, 360, 361, 367, 371, 372, 374, 375, 376, 379, 380, 382,
             384, 388, 389, 390, 391, 393, 394, 397, 398, 399, 400, 403, 404, 405, 407,
             408, 410, 411, 413, 415, 417, 418, 420, 422, 424, 425, 426, 427, 430, 431,
             436, 437, 441, 442, 443, 444, 446, 447, 449, 451, 453, 454, 457, 458, 460,
             461, 463, 465, 466, 468, 469, 470, 471, 473, 474, 480, 481, 482, 484, 485,
             487, 489, 492, 493, 494, 495, 496, 497, 498, 500, 502, 504, 506, 508, 509,
             510, 512, 513, 514, 515, 517, 519, 522, 523, 524, 525, 528, 531, 532, 534,
             535, 537, 541, 542, 543, 544, 545, 546, 547, 548, 551, 552, 553, 555, 556,
             557, 559, 560, 562, 565, 568, 570, 571, 573, 574, 576, 578, 579, 585, 586,
             588, 589, 592, 595, 598, 599, 600, 602, 604, 607, 609, 610, 611, 612, 614,
             615, 616, 617, 619, 620, 621, 624, 627, 628, 629, 631, 632, 633, 634, 640,
             643, 645, 647, 649, 650, 652, 654, 656, 657, 658, 660, 661, 662, 663, 666,
             668, 669, 670, 671, 673, 675, 676, 677, 679, 681, 682, 685, 687, 690, 693,
             696, 697, 699, 700, 701, 704, 706, 708, 709, 710, 711, 713, 714, 715, 716,
             717, 718, 721, 724, 726, 728, 729, 730, 731, 732, 733, 734, 735, 738, 739,
             741, 742, 750, 751, 754, 755, 757, 759, 762, 765, 766, 767, 769, 772, 773,
             777, 778, 780, 781, 782, 783, 786, 787, 788, 794, 795, 796, 797, 798, 799,
             802, 803, 804, 805, 806, 807, 808, 809, 810, 812, 813, 814, 815, 817, 818,
             820, 825, 826, 829, 830, 831, 832, 833, 840, 841, 845, 846, 847, 849, 851,
             852, 853, 857, 858, 859, 860, 861, 862, 866, 868, 869, 870, 871, 874, 876,
             877, 878, 879, 880, 883, 884, 885, 886, 887, 888, 889, 892, 894, 895, 897,
             898, 900, 902, 907, 908, 909, 910, 911, 912, 914, 915, 916, 919, 920, 923,
             924, 925, 926, 927, 928, 930, 931, 933, 934, 936, 937, 939, 940, 941, 943,
             945, 947, 948, 951, 954, 955, 958, 959, 960, 961, 962, 966, 967, 968, 970,
             972, 973, 974, 975, 976, 978, 979, 981, 982, 983, 984, 985, 990, 991, 993,
             994, 995, 996, 997, 999, 1000};

int d(int i)
{
    int res = i;

    int dd = i;
    while (dd > 0)
    {
        res += (dd % 10);
        dd /= 10;
    }

    for (int p : primes)
    {
        if (i % p == 0)
        {
            res += p;
            while (i % p) i /= p;
        }
    }

    return res;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool p = false;
        for (int x : dds)
        {
            if (x == n)
            {
                p = true;
                cout << "Yes" << endl;
                break;
            }
        }
        if (!p)
        {
            cout << "No" << endl;
        }
    }

//    set<int> ll;
//    int i = 1, j;
//    while (i <= 1000)
//    {
//        j = d(i);
//        if (j <= 1000 && j>= 4)
//        {
//            ll.insert(j);
//        }
//        ++i;
//    }
//    cout << "{";
//    for(int u : ll)
//    {
//        cout << u << ", " ;
//    }
//    cout << "}" << endl;

    return 0;
}
