def eliminate_left_recursion(grammar):
    new_productions = {}
    for nonterminal in grammar:
        productions_with_recursion = []
        productions_without_recursion = []
        for production in grammar[nonterminal]:
            if production[0] == nonterminal:
                productions_with_recursion.append(production)
            else:
                productions_without_recursion.append(production)
        if len(productions_with_recursion) > 0:
            new_nonterminal = nonterminal + "'"
            for production in productions_without_recursion:
                new_productions.setdefault(nonterminal, []).append(production + new_nonterminal)
            new_production_with_recursion = []
            for production in productions_with_recursion:
                new_production_with_recursion.append(production[1:] + new_nonterminal)
            new_production_with_recursion.append('ε')
            new_productions.setdefault(new_nonterminal, []).extend(new_production_with_recursion)
        else:
            new_productions[nonterminal] = grammar[nonterminal]
    return new_productions

def compute_first(grammar, symbol):
    first = set()
    if symbol not in grammar:
        first.add(symbol)
    else:
        for production in grammar[symbol]:
            if production[0] == symbol:
                continue
            for symbol in production:
                first_set = set(compute_first(grammar, symbol))
                first |= {s for s in first_set if isinstance(s, str)}
                if '' not in first_set:
                    break
            else:  # no break in the loop over symbols
                first.add('')
    return first

def compute_follow(grammar, nonterminal, computed):
    follow = set()
    if nonterminal == 'S':
        follow.add('$')
    for symbol in grammar:
        for production in grammar[symbol]:
            if nonterminal in production:
                index = production.index(nonterminal)
                if index == len(production) - 1:
                    if symbol != nonterminal and symbol not in computed:
                        computed.add(symbol)
                        follow |= compute_follow(grammar, symbol, computed)
                else:
                    for next_symbol in production[index+1:]:
                        if next_symbol not in grammar:
                            follow.add(next_symbol)
                            break
                        else:
                            first_set = set(compute_first(grammar, next_symbol))
                            if '' not in first_set:
                                follow |= first_set
                                break
                            else:
                                first_set.remove('')
                                follow |= first_set
                                if next_symbol == production[-1] and symbol != nonterminal and symbol not in computed:
                                    computed.add(symbol)
                                    follow |= compute_follow(grammar, symbol, computed)
                    else:  # no break in the loop over next_symbol
                        if symbol != nonterminal and symbol not in computed:
                            computed.add(symbol)
                            follow |= compute_follow(grammar, symbol, computed)
    follow_strings = [str(s) for s in follow]
    return set(follow_strings)


grammar = {
    'E': ['E+T', 'T'],
    'T': ['T*F', 'F'],
    'F': ['(E)', 'id']
}

print('Original Grammar:')
for nonterminal in grammar:
    print(nonterminal + ' -> ' + ' | '.join(grammar[nonterminal]))

new_grammar = eliminate_left_recursion(grammar)
print('\nModified Grammar:')
for nonterminal in new_grammar:
    print(nonterminal + ' -> ' + ' | '.join(new_grammar[nonterminal]))

print('\nFIRST sets:')
for nonterminal in new_grammar:
    first_set = compute_first(new_grammar, nonterminal)
    formatted_set = [repr(s) for s in first_set]
    print(nonterminal + ': {' + ', '.join(formatted_set) + '}')

print('\nFOLLOW sets:')
for nonterminal in new_grammar:
    follow_set = compute_follow(new_grammar, nonterminal, set())
    print(nonterminal + ': {' + ', '.join(follow_set) + '}')

print('\nParsing table:')
parsing_table = {}
is_LL1 = True
for nonterminal in new_grammar:
    for production in new_grammar[nonterminal]:
        first_set = set(compute_first(new_grammar, production[0]))
        if '' in first_set:
            follow_set = compute_follow(new_grammar, nonterminal, set())
            first_set.remove('')
            for terminal in follow_set:
                if (nonterminal, terminal) in parsing_table:
                    print('Conflict at: ', nonterminal, terminal)
                    is_LL1 = False
                parsing_table[(nonterminal, terminal)] = production
        else:
            for terminal in first_set:
                if (nonterminal, terminal) in parsing_table:
                    print('Conflict at: ', nonterminal, terminal)
                    is_LL1 = False
                parsing_table[(nonterminal, terminal)] = production
for nonterminal in new_grammar:
    for terminal in compute_follow(new_grammar, nonterminal, set()):
        if (nonterminal, terminal) not in parsing_table:
            parsing_table[(nonterminal, terminal)] = 'error'
            
# Print the parsing table in row-column format
print('\n', ' '*3, end='')
for terminal in set(term for nonterm, term in parsing_table):
    print(f'{terminal:^10}', end='')
print()
for nonterminal in new_grammar:
    print(f'{nonterminal:^3}', end='')
    for terminal in set(term for nonterm, term in parsing_table):
        if parsing_table.get((nonterminal, terminal), None) is not None:
            print(f'{parsing_table[(nonterminal, terminal)]:^10}', end='')
        else:
            print(f'{"":^10}', end='')
    print()

if is_LL1:
    print('\nThe given grammar is LL(1)')
else:
    print('\nThe given grammar is not LL(1)')