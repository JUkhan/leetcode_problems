#include "print.h"

void learn_container()
{
    vector<int> nums{1, 2, 5, 2, 9, 7};

    print("Transform:");
    vector<int> res(nums.size());
    int product = accumulate(nums.begin(), nums.begin() + 3, 1, [](int a, int b)
                             { return a * b; });
    transform(nums.begin(), nums.end(), res.begin(), [&](int a)
              { return product / a; });
    print(res);

    print("transform by accumulate");
    auto pair_vec = accumulate(nums.begin(), nums.end(), vector<pair<int, int>>(), [](vector<pair<int, int>> acc, int a)
                               {
        acc.push_back({a,a+1});
        return acc; });
    print(pair_vec);

    print("partial_sum | scan");
    vector<int> ps_res(nums.size());
    partial_sum(nums.begin(), nums.end(), ps_res.begin(), [](int a, int b)
                { return a * b; });
    print(ps_res);

    print("all_of");
    cout << (all_of(nums.begin(), nums.end(), [](int a)
                    { return a > 0; })
                 ? "all positive"
                 : "not all positive")
         << endl;
    // none_of
    // any_of
    // copy_n
    print("iota: init vector followed by asc order");
    vector<int> box(10);
    iota(box.begin(), box.end(), 1);
    print(box);

    print("min value");

    cout << *min_element(nums.begin(), nums.end());
    print("max value");
    cout << *max_element(nums.begin(), nums.end());
    print("a value number of times exist");
    cout << count(nums.begin(), nums.end(), 2);
    print("find a value");
    auto find_res = find(nums.begin(), nums.end(), 2);
    if (find_res != nums.end())
    {
        print("value found");
    }
    else
    {
        print("not found");
    }
    print("-----group-----");

    unordered_map<string, vector<string>> map{
        {"abt", {"bat"}},
        {"ant", {"nat", "tan"}},
        {"aet", {"ate", "eat", "tea"}}};
    vector<vector<string>> output;
    for (auto &p : map)
    {
        output.push_back(map[p.first]);
    }
    print(output);
    print("end container");
}

void learn_string_compare()
{
    print("Syntax 1: Compares the string *this with the string str.");
    string s1 = "jasim", s2 = "";
    if (s1.compare("jasim") == 0)
        print("equal");
    if (s1.compare("rasim") < 0)
        print("smaller");
    if (s1.compare("aasim") > 0)
        print("greater");

    print("syntex 2");
    s1 = "Geeks";
    s2 = "forGeeks";
    if ((s2.compare(3, 5, s1)) == 0)
        cout << "Here, " << s1 << " are " << s2;
    else
        cout << "Strings didn't match ";

    print("syntex 3");

    if ((s1.compare(0, 5, s2, 3, 5)) == 0)
        cout << "Welcome to " << s1 << " " << s2 << " World";

    else
        cout << "Strings didn't match ";

    print("end string compare");
}

void learn_regex()
{
    print("regex:");
    string s = "Some people, when confronted with a problem, think "
               "\"I know, I'll use regular expressions.\" "
               "Now they have two problems.";
    regex self_regex("REGULAR EXPRESSIONS",
                     regex_constants::ECMAScript | regex_constants::icase);
    if (regex_search(s, self_regex))
    {
        print("Text contains the phrase 'regular expressions'\n");
    }

    regex word_regex("(\\w+)");
    auto words_start = sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = sregex_iterator();
    cout << "Found "
         << distance(words_start, words_end)
         << " words" << endl;
   
    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    while (words_start != words_end)
    {
        auto m = *words_start;
        string str = m.str();
        if (str.size() > N)
            cout << m.str() << " ";
        words_start++;
    }

    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$1]");
    std::cout << new_s << '\n';
}

void run()
{
    cout << "learning..." << endl;
    // learn_container();
    // learn_string_compare();
    learn_regex();
}