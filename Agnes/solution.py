#!/usr/bin/env python3
from collections import defaultdict, namedtuple
from sys import stdin


Arc = namedtuple('Arc', ('head', 'weight', 'tail'))


def min_spanning_arborescence(arcs, source):
    good_arcs = []
    quotient_map = {arc.tail: arc.tail for arc in arcs}
    quotient_map[source] = source
    while True:
        min_arc_by_tail_rep = {}
        successor_rep = {}
        for arc in arcs:
            if arc.tail == source:
                continue
            tail_rep = quotient_map[arc.tail]
            head_rep = quotient_map[arc.head]
            if tail_rep == head_rep:
                continue
            if tail_rep not in min_arc_by_tail_rep or min_arc_by_tail_rep[tail_rep].weight > arc.weight:
                min_arc_by_tail_rep[tail_rep] = arc
                successor_rep[tail_rep] = head_rep
        cycle_reps = find_cycle(successor_rep, source)
        if cycle_reps is None:
            good_arcs.extend(min_arc_by_tail_rep.values())
            return spanning_arborescence(good_arcs, source)
        good_arcs.extend(min_arc_by_tail_rep[cycle_rep] for cycle_rep in cycle_reps)
        cycle_rep_set = set(cycle_reps)
        cycle_rep = cycle_rep_set.pop()
        quotient_map = {node: cycle_rep if node_rep in cycle_rep_set else node_rep for node, node_rep in quotient_map.items()}


def find_cycle(successor, sink):
    visited = {sink}
    for node in successor:
        cycle = []
        while node not in visited:
            visited.add(node)
            cycle.append(node)
            node = successor[node]
        if node in cycle:
            return cycle[cycle.index(node):]
    return None


def spanning_arborescence(arcs, sink):
    arcs_by_head = defaultdict(list)
    for arc in arcs:
        if arc.tail == sink:
            continue
        arcs_by_head[arc.head].append(arc)
    solution_arc_by_tail = {}
    stack = arcs_by_head[sink]
    while stack:
        arc = stack.pop()
        if arc.tail in solution_arc_by_tail:
            continue
        solution_arc_by_tail[arc.tail] = arc
        stack.extend(arcs_by_head[arc.tail])
    return solution_arc_by_tail

def main():
    _ = int(stdin.readline()[:-1])
    people = stdin.readline()[:-1].split()

    transmissions = []
    for line in stdin:
        line = line[:-1].split()
        transmissions.append(Arc(line[0], 1/float(line[2]), line[1]))

    possibles = []
    for person in people:
        arb = min_spanning_arborescence(transmissions, person)
        possibles.append((sum([arc.weight for _,arc in arb.items()]), arb))

    possibles = sorted(possibles)

    solution = sorted([(val.head, val.tail, val.weight) for _,val in possibles[0][1].items()])

    for each in solution:
        print(each[0], each[1])

if __name__ == '__main__':
    main()
