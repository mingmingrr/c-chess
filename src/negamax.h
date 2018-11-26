#pragma once

#define negamax_Prototype( \
	Namespace, \
	Node, Value, Move, \
	MoveBuffer, ValueMin, \
	Terminal, ChildMoves, Heuristic \
) \
	Node* Namespace##negamax_root( \
		Node* node, \
		unsigned depth, \
		signed color \
	); \
	Value Namespace##negamax_node( \
		Node* node, \
		unsigned depth, \
		Value alpha, \
		Value beta, \
		signed color \
	);

#define negamax_Generate( \
	Namespace, \
	Node, Value, Move, \
	MoveBuffer, ValueMin, \
	Terminal, ChildMoves, Heuristic \
) \
	negamax_Prototype( \
		Namespace, \
		Node, Value, Move, \
		MoveBuffer, ValueMin, \
		Terminal, ChildMoves, Heuristic \
	) \
	Node* Namespace##negamax_root( \
		Node* node, \
		unsigned depth, \
		signed color \
	) { \
		if(depth-- == 0 || Terminal(node)) \
			return (Node*)0; \
		MoveBuffer(child); \
		Value alpha = (ValueMin) * color; \
		Value beta = -(ValueMin) * color; \
		Node* top = (Node*)0; \
		Node* end = ChildMoves(child, node); \
		Value value = ValueMin; \
		for(; child != end; ++child) { \
			Value val = Namespace##negamax_node \
				(child, depth, -beta, -alpha, -color); \
			if(-val > value) { \
				value = val; \
				top = child; \
				if(value > alpha) { \
					alpha = value; \
					if(alpha >= beta) break; \
				} \
			} \
		} \
		return top; \
	} \
	Value Namespace##negamax_node( \
		Node* node, \
		unsigned depth, \
		Value alpha, \
		Value beta, \
		signed color \
	) { \
		if(depth-- == 0 || Terminal(node)) \
			return color * Heuristic(node); \
		MoveBuffer(child); \
		Move* end = ChildMoves(child, node); \
		Value value = ValueMin; \
		for(; child != end; ++child) { \
			Value val = Namespace##negamax_node \
				(child, depth, -beta, -alpha, -color); \
			if(-val > value) { \
				value = val; \
				if(value > alpha) { \
					alpha = value; \
					if(alpha >= beta) break; \
				} \
			} \
		} \
		return value; \
	}

