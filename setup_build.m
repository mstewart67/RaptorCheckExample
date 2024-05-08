function rc = setup_build()
% SETUP_BUILD - Sets the compiler for the model under test. Loads system, applies change, then saves and closes. 

    disp('Setting up model RaptorCheckExample for Jenkins build.');

    % loads the model into memory, so we can modify it
    load_system('RaptorCheckExample');

    % Find what RCM112 Compilers are installed
    compilers = raptor_find_58NN_compilers();
    
    if isempty(compilers)
        error('Failed to find a compiler installed for SPC58NN');
    end

    % Find target def block
    target_blk = ['RaptorCheckExample/raptor_target_def'];

    % Set compiler to target def block, in this instance we are not looking for a specific version to use, such as HighTec.
    set_param(target_blk, 'compiler', compilers{1});

    % Enable code generation report
    set_param('RaptorCheckExample', GenerateReport="on");

    close_system('RaptorCheckExample');

    disp('Finished setting up model.');

end