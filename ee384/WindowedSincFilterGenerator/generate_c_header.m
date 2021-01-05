function generate_c_header(h)
    fid = fopen('filter.h','wt');
    fprintf(fid, 'double filter[');
    fprintf(fid, '%d', length(h));
    fprintf(fid, '] = {\n');
    
    for i = 1:length(h)
        fprintf(fid, '%.25f', h(i));
        if(i ~= length(h))
            fprintf(fid, ', ');
        end
        if(mod(i, 4) == 0)
            fprintf(fid, '\n');
        end
    end
    fprintf(fid, '};');
    fclose(fid);
end