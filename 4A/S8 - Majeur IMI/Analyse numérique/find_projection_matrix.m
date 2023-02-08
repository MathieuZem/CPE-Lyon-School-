%*************************************************************************
% On transforme la matrice n par n correspondant � l'image en un vecteur
% de longueur n^2. Ensuite, � partir d'une g�om�trie d'acquisition pr�d�finie
% dans la fonction, on calcule la matrice de projection A de taille
% appropri�e qui, une fois appliqu�e � l'image, donne la projection des
% pixels de cette image suivant les orientations pr�d�finies par la g�om�trie
% d'acquisition.
% Mohammad Arzi - Mars 2018

function A=find_projection_matrix(n)
    A=zeros(3*n^2,n^2);
    IA=1;
    for k1=1:n
        a=[k1;0];
        for k2=0:n
            b=[0;k2];
            [indm,windm,ind1,ind2]=find_ray_pixel_incidence(n,a,b);
            for kk=1:length(ind1)
                JA=(ind2(kk)-1)*n+ind1(kk);
                A(IA,JA)=windm(ind1(kk),ind2(kk));
            end
            IA=IA+1;
        end
        
        for k2=1:n
            b=[k2;n];
            [indm,windm,ind1,ind2]=find_ray_pixel_incidence(n,a,b);
            for kk=1:length(ind1)
                JA=(ind2(kk)-1)*n+ind1(kk);
                A(IA,JA)=windm(ind1(kk),ind2(kk));
            end
            IA=IA+1;
        end
        
        for k2=n-1:1
            b=[n;k2];
            [indm,windm,ind1,ind2]=find_ray_pixel_incidence(n,a,b);
            for kk=1:length(ind1)
                JA=(ind2(kk)-1)*n+ind1(kk);
                A(IA,JA)=windm(ind1(kk),ind2(kk));
            end
            IA=IA+1;
        end
    end
end
