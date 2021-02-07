import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class w11_flow {

	public static void main(String[] args) {
		// Initialize
		Scanner inputStreamScanner = new Scanner(System.in);

		int numberOfNode = inputStreamScanner.nextInt();
		int numberOfEdge = inputStreamScanner.nextInt();
		int totalData = inputStreamScanner.nextInt();

		HashMap<String, HashMap<String, Integer>> graph = new HashMap<String, HashMap<String, Integer>>();
		HashMap<String, HashMap<String, Integer>> flowMap = new HashMap<String, HashMap<String, Integer>>();

		String inputString;
		for (int i = 0; i < numberOfNode; i++) {
			inputString = inputStreamScanner.next();
			graph.put(inputString, new HashMap<String, Integer>());
			flowMap.put(inputString, new HashMap<String, Integer>());
		}

		String startNode, endNode;
		int bandwidth;
		for (int i = 0; i < numberOfEdge; i++) {
			startNode = inputStreamScanner.next();
			endNode = inputStreamScanner.next();
			bandwidth = inputStreamScanner.nextInt();
			if (graph.get(startNode).containsKey(endNode)) {
				graph.get(startNode).replace(endNode, graph.get(startNode).get(endNode) + bandwidth);
				graph.get(endNode).replace(startNode, graph.get(endNode).get(startNode) + bandwidth);
			} else {
				graph.get(startNode).put(endNode, bandwidth);
				graph.get(endNode).put(startNode, bandwidth);
				flowMap.get(startNode).put(endNode, 0);
				flowMap.get(endNode).put(startNode, 0);
			}
		}

		startNode = inputStreamScanner.next();
		endNode = inputStreamScanner.next();

		HashMap<String, String> parentMap = new HashMap<>();
		String nodeU, nodeV;
		int maxFlow = 0;
		int currentFlow;
		while (bfs(graph, flowMap, startNode, endNode, parentMap)) {
			currentFlow = Integer.MAX_VALUE;
			nodeV = endNode;
			while (true) {
				nodeU = parentMap.get(nodeV);
				if (nodeU == null) {
					if (nodeV.equals(startNode))
						break;
					inputStreamScanner.close();
					throw new RuntimeException("start node not found");
				} else if (nodeV.equals(startNode)) {
					break;
				}
				currentFlow = Math.min(currentFlow, graph.get(nodeU).get(nodeV) - flowMap.get(nodeU).get(nodeV));
				nodeV = nodeU;
			}
			nodeV = endNode;
			while (true) {
				nodeU = parentMap.get(nodeV);
				if (nodeU == null) {
					if (nodeV.equals(startNode))
						break;
					inputStreamScanner.close();
					throw new RuntimeException("start node not found");
				} else if (nodeV.equals(startNode)) {
					break;
				}
				flowMap.get(nodeU).replace(nodeV, flowMap.get(nodeU).get(nodeV) + currentFlow);
				flowMap.get(nodeV).replace(nodeU, flowMap.get(nodeV).get(nodeU) - currentFlow);
				nodeV = nodeU;
			}
			if (currentFlow == Integer.MAX_VALUE) {
				inputStreamScanner.close();
				throw new RuntimeException("flow calculation failed");
			}
			maxFlow = maxFlow + currentFlow;
		}

		// Output
		System.out.printf("%d\n", totalData % maxFlow == 0 ? totalData / maxFlow : (totalData / maxFlow) + 1);

		// Finalize
		inputStreamScanner.close();
		return;
	}

	private static boolean bfs(HashMap<String, HashMap<String, Integer>> graph,
			HashMap<String, HashMap<String, Integer>> flowMap, String startNode, String endNode,
			HashMap<String, String> parentMap) {
		// Initialize
		parentMap.clear();

		ArrayList<String> visited = new ArrayList<String>();
		ArrayList<String> queue = new ArrayList<String>();

		String currentNode;
		queue.add(startNode);
		parentMap.put(startNode, null);
		while (!queue.isEmpty()) {
			currentNode = queue.remove(0);
			if (!visited.contains(currentNode)) {
				visited.add(currentNode);
				for (String nextNode : graph.get(currentNode).keySet()) {
					if (!visited.contains(nextNode)) {
						if (graph.get(currentNode).get(nextNode) - flowMap.get(currentNode).get(nextNode) > 0) {
							if (nextNode.equals(endNode)) {
								parentMap.put(endNode, currentNode);
								break;
							}
							parentMap.put(nextNode, currentNode);
							queue.add(nextNode);
						}
					}
				}
			}
		}
		if (parentMap.get(endNode) != null) {
			return true;
		}
		return false;
	}

}