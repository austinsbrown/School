#include "graph.h"
using namespace std;

Graph::Graph()
{
    vertices = NULL;
}


Graph::~Graph()
{
    while(vertices != NULL)
    {
        while(vertices->edgePtr != NULL)
        {
            EdgeNode* temp = vertices->edgePtr;
            vertices->edgePtr = vertices->edgePtr->nextEdge;
            delete temp;
        }

        VertexNode* temp = vertices;
        vertices = vertices->nextVertex;
        delete temp;
    }
}


void Graph::AddVertex(string v)
{
    if(vertices == NULL)
    {
        vertices = new VertexNode;
        vertices->vname = v;
        vertices->nextVertex = NULL;
        vertices->edgePtr = NULL;
        vertices->mark = false;
    }

    else
    {
        VertexNode* temp = new VertexNode;
        temp->nextVertex = vertices;
        vertices = temp;
        vertices->edgePtr = NULL;
        vertices->vname = v;
        vertices->mark = false;
    }
}	

  
void Graph::AddEdge(string s, string d, int w)
{
    try
    {
        EdgeNode* temp = new EdgeNode;
        delete temp;
    }

    catch(bad_alloc)
    {
        throw GraphFull();
    }

    if(VertexExists(s) == NULL || VertexExists(d) == NULL)
    {
        throw GraphVertexNotFound();
    }

    VertexNode* v = VertexExists(s);
    if(v->edgePtr == NULL)
    {
        v->edgePtr = new EdgeNode;
        v->edgePtr->destination = VertexExists(d);
        v->edgePtr->weight = w;
        v->edgePtr->nextEdge = NULL;
    }

    else
    {
        EdgeNode* temp = new EdgeNode;
        temp->destination = VertexExists(d);
        temp->weight = w;
        temp->nextEdge = v->edgePtr;
        v->edgePtr = temp;
    }
}	

	
VertexNode* Graph::VertexExists(string v) const
{
    VertexNode* temp;
    temp = vertices;

    while(temp->vname != v)
    {
        if(temp->nextVertex != NULL)
        {
            temp = temp->nextVertex;
        }
        else
        {
            return NULL;
        }
    }
    return temp;
}
  

EdgeNode* Graph::EdgeExists(string s, string d) const
{
    if(VertexExists(s) == NULL || VertexExists(d) == NULL)
    {
        throw GraphVertexNotFound();
    }

    EdgeNode* temp = VertexExists(s)->edgePtr;
    while(temp->destination->vname != d)
    {
        if(temp->nextEdge != NULL)
        {
            temp = temp->nextEdge;
        }
        else
        {
            return NULL;
        }
    }
    return temp;
}
	

int  Graph::WeightIs(string s, string d)
{
    if(EdgeExists(s, d) == NULL)
    {
        throw GraphEdgeNotFound();
    }

    return EdgeExists(s, d)->weight;
    
}  
  

void Graph::ClearMarks()
{
    VertexNode* temp = vertices;

    temp->mark = false;
    while(temp->nextVertex != NULL)
    {
        temp = temp->nextVertex;
        temp->mark = false;
    }
}	
  
	
void Graph::MarkVertex(string v)
{
    if(VertexExists(v) == NULL)
    {
        throw GraphVertexNotFound();
    }
    VertexExists(v)->mark = true;
}	
  
	
bool Graph::IsMarked(string v)
{
    if(VertexExists(v) != NULL)
    {
        return VertexExists(v)->mark;
    }

    else
    {
        throw GraphVertexNotFound();
    }
    

} 
  

void Graph::GetToVertices(string V, queue<string>& q)
{
    if(VertexExists(V) == NULL)
    {
        throw GraphVertexNotFound();
    }

    EdgeNode* temp = VertexExists(V)->edgePtr;

    while(temp != NULL)
    {
        if(temp->destination->mark == false)
        {
            q.push(temp->destination->vname);
        }
        temp = temp->nextEdge;
    }
}
  
	
void Graph::DepthFirstSearch(string startVertex, string endVertex, queue<string>& path)
{
    if(VertexExists(startVertex) == NULL || VertexExists(endVertex) == NULL)
    {
        throw GraphVertexNotFound();
    }
    queue <string> q;
    stack <string> s;
    bool found = false;
    string vertex;
    string item;

    ClearMarks();
    s.push(startVertex);
    
    do
    {
        vertex = s.top();
        s.pop();
        if(vertex == endVertex)
        {
            path.push(vertex);
            found = true;
        }
        else
        {
            if(!IsMarked(vertex))
            {
                MarkVertex(vertex);
                path.push(vertex);
                GetToVertices(vertex, q);

                while(!q.empty())
                {
                    item = q.front();
                    q.pop();
                    if(!IsMarked(item))
                    {
                        s.push(item);
                    }
                }
            }
        }
        
    } while (!s.empty() && !found);

    if(!found)
    {
        while(!path.empty())
        {
            path.pop();
        }
    }
}
  

void Graph::BreadthFirstSearch(string startVertex, string endVertex, queue<string>& visitedq)
{
    if(VertexExists(startVertex)==NULL||VertexExists(endVertex)==NULL)
    {
        throw GraphVertexNotFound();
    }

    bool found = false;
    string vertex, item;
    queue<string> q;
    queue<string> vq;
    ClearMarks();

    q.push(startVertex);

    do
    {
        vertex = q.front();
        q.pop();

        if(vertex == endVertex)
        {
            visitedq.push(vertex);
            found = true;
        }

        else
        {
            if(!IsMarked(vertex))
            {
                MarkVertex(vertex);
                visitedq.push(vertex);
                GetToVertices(vertex, vq);
            }

            while(!vq.empty())
            {
                item = vq.front();
                vq.pop();

                if(!IsMarked(item))
                {
                    q.push(item);
                }
            }
        }
    } while (!q.empty() && !found);
    
    if(!found)
    {
        while(!visitedq.empty())
        {
            visitedq.pop();
        }
    }
}
  