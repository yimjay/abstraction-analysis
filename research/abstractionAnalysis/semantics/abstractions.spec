
Stack: { top elem ... } with
{
  Pop: { top elem1 elem2 ...} -> elem1 * { top elem2 ...};
  Push: { top elem1 ... } * elem -> { top elem elem1 ...};
  Empty : { top } -> true;
        { top elem ...} -> false
};

Queue: { front elem ... back} with
{
  Pop: {front elem ... back} -> elem * {front ... back};
  Push: {front elem1 ... back} * elem2 -> {front elem1 ... elem2 back}; 
  Empty : { front back} -> true;
          { front elem ... back} -> false;
};

